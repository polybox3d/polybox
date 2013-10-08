#ifndef MCODE_H
#define MCODE_H

namespace MCode {
/**
 * @brief The MCodeFlags enum Base value for Polybox M-Code.
 */
enum MCodeFlags
{
    ASK_CNC_UPDATE=600, ASK_PRINTER_UPDATE=630, ASK_LABVIEW_UPDATE=620, ASK_SCANNER_UPDATE=610
};

}

#endif // MCODE_H
