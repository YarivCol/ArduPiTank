import serial
import IPython
import ArduTank_pb2 as proto

class command(object):

	def __init__(self, command_type, stream):
		self.cmd = proto.ArduTankCommand()
		self.command_type = command_type
		self.response_type = getattr(proto, command_type.__name__.replace("Command", "Response"), None)
		self.stream = stream
	
	def __call__(self, *args, **kwargs):
		cmd_obj = self.command_type(*args, **kwargs)
		getattr(self.cmd, self.command_type.__name__ + "Value").CopyFrom(cmd_obj)
		self.stream.write(self._encode_cmd())
		if self.response_type:
			len = ord(self.stream.read(1))
			return proto.ArduTankResponse.FromString(self.stream.read(len))

	def _encode_cmd(self):
		encoded_cmd = self.cmd.SerializeToString()
		return chr(len(encoded_cmd)) + encoded_cmd
		
class commands(object):

	def __init__(self, stream):
		for attr in dir(proto):
			if "Command" in attr:
				setattr(self, attr, command(getattr(proto, attr), stream))

if __name__ == "__main__":
	IPython.embed()
