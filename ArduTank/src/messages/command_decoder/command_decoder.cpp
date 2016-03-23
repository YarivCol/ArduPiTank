#include "command_decoder.h"
#include "../../protos/output/ArduTank.pb.h"

const pb_field_t* CommandDecoder::decode_command_type(pb_istream_t *stream)
{
    pb_wire_type_t wire_type;
    uint32_t tag;
    bool eof;

    while (pb_decode_tag(stream, &wire_type, &tag, &eof))
    {
        if (wire_type == PB_WT_STRING)
        {
            const pb_field_t *field;
            for (field = ArduTankCommand_fields; field->tag != 0; field++)
            {
                if (field->tag == tag && (field->type & PB_LTYPE_SUBMESSAGE))
                {
                    /* Found our field. */
                    return (pb_field_t*) field->ptr;
                }
            }
        }

        /* Wasn't our field.. */
        pb_skip_field(stream, wire_type);
    }

    return NULL;
}

bool CommandDecoder::decode_command_contents(pb_istream_t *stream, const pb_field_t fields[], void *dest_struct)
{
    pb_istream_t substream;
    bool status;
    if (!pb_make_string_substream(stream, &substream))
        return false;

    status = pb_decode(&substream, fields, dest_struct);
    pb_close_string_substream(stream, &substream);
    return status;
}
