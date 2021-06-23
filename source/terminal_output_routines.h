 /**********************************************************************************************************************************\
 * Title : Terminal printing support routines                                                                                       *
 *                                                                                                                                  *
 * Author : Gert van Biljon                                                                                                         *
 *                                                                                                                                  *
 * EMail : gertvb@gmail.com or gert@techexplorer.co.za                                                                              *
 \**********************************************************************************************************************************/

 /**********************************************************************************************************************************\
 * What am I : Just a collection of helper routines for printing to a Terminal like the DOS command line, TeraTerm on Windows or    *
 *             XTerm on *nix that I have collected over many years.                                                                 *
 *                                                                                                                                  *
 * Included : 1. Defines for changing printed foreground or background colours with VT100 escape codes                              *
 *            2. Formatting an integer number as a binary number                                                                    *
 *            3. Extracting and formatting Author, Subversion and Compiler stuff                                                    *
 *            4. Formatting a line of 6 * coloured characters, with each character's position from left defined by its value in a   *
 *               range of 0 - 65535                                                                                                 *
 *            5. Formatting a line of 6 * coloured values, with each character's foreground/background colour determined by whether *
 *               the value is above/below a specified threshold                                                                     *
 *                                                                                                                                  *
 \**********************************************************************************************************************************/

 /**********************************************************************************************************************************\
 $Author:: Gert_v_B                                                                                                                 $
 $Date:: 2020-11-16 07:26:57 +0200 (Mon, 16 Nov 2020)                                                                               $
 $Revision:: 1254                                                                                                                   $
 $URL:: https://techexplorer/svn/SVN_Repository/c/terminal_output_routines/terminal_output_routines.h                               $
 \**********************************************************************************************************************************/

#include <stdint.h>

 /**********************************************************************************************************************************\
 * Function name : print numerical values as binary                                                                                 *
 *                                                                                                                                  *
 * Author : Internet                                                                                                                *
 *                                                                                                                                  *
 * Sources : https://stackoverflow.com/users/289138/william-whyte                                                                   *
 *           https://stackoverflow.com/users/432509/ideasman42                                                                      *
 *           https://stackoverflow.com/users/7227940/et7f3xiv                                                                       *
 *                                                                                                                                  *
 * Use : long long int variable = 1648646756487983144ll;                                                                            *
 *       printf("My variable as binary"                                                                                             *
 *              PRINTF_BINARY_PATTERN_INT64 "\n",                                                                                   *
 *              PRINTF_BYTE_TO_BINARY_INT64(variable));                                                                             *
 *                                                                                                                                  *
 * What do I do : I print a numerical value formatted as binary                                                                     *
 \**********************************************************************************************************************************/
#define PRINTF_BINARY_SEPARATOR " "
#define PRINTF_BINARY_PATTERN_INT8 "%c%c%c%c" PRINTF_BINARY_SEPARATOR "%c%c%c%c"
#define PRINTF_BYTE_TO_BINARY_INT8(i)   (((i) & 0x80ll) ? '1' : '0'), \
                                        (((i) & 0x40ll) ? '1' : '0'), \
                                        (((i) & 0x20ll) ? '1' : '0'), \
                                        (((i) & 0x10ll) ? '1' : '0'), \
                                        (((i) & 0x08ll) ? '1' : '0'), \
                                        (((i) & 0x04ll) ? '1' : '0'), \
                                        (((i) & 0x02ll) ? '1' : '0'), \
                                        (((i) & 0x01ll) ? '1' : '0')

#define PRINTF_BINARY_PATTERN_INT16    PRINTF_BINARY_PATTERN_INT8     PRINTF_BINARY_SEPARATOR    PRINTF_BINARY_PATTERN_INT8
#define PRINTF_BINARY_PATTERN_INT32    PRINTF_BINARY_PATTERN_INT16    PRINTF_BINARY_SEPARATOR    PRINTF_BINARY_PATTERN_INT16
#define PRINTF_BINARY_PATTERN_INT64    PRINTF_BINARY_PATTERN_INT32    PRINTF_BINARY_SEPARATOR    PRINTF_BINARY_PATTERN_INT32

#define PRINTF_BYTE_TO_BINARY_INT16(i) PRINTF_BYTE_TO_BINARY_INT8 ((i) >>  8), PRINTF_BYTE_TO_BINARY_INT8(i)
#define PRINTF_BYTE_TO_BINARY_INT32(i) PRINTF_BYTE_TO_BINARY_INT16((i) >> 16), PRINTF_BYTE_TO_BINARY_INT16(i)
#define PRINTF_BYTE_TO_BINARY_INT64(i) PRINTF_BYTE_TO_BINARY_INT32((i) >> 32), PRINTF_BYTE_TO_BINARY_INT32(i)

 /**********************************************************************************************************************************\
 * VT200 escape codes to output text in colour in TerraTerm/xterm                                                                   *
 * http://www.johnrepici.com/serendipity/archives/192-The-xterm-256-color-table-set-colors-in-xterm-or-PuTTY.html                   *
 *                                                                                                                                  *
 * First encountered escape codes in Paul Somerson's excellent classic of 1989                                                      *
 * "PC Magazine DOS PowerTools: Techniques, Tricks and Utilities"                                                                   *
 *                                                                                                                                  *
 * In TeraTerm, you can specify orange as an rgb colour by sending the following string : "\033[38;2;255;127;0m"                    *
 *                                                                                                                                  *
 * \033[ : escape code                                                                                                              *
 * 38;   : foreground, use 48 for background                                                                                        *
 * 2;    : escape mode                                                                                                              *
 * 225   : Red value (0 - 255)                                                                                                      *
 * 127   : Green value (0 - 255)                                                                                                    *
 * 0     : Blue (0 - 255)                                                                                                           *
 * m     : end of escape code                                                                                                       *
 *                                                                                                                                  *
 * In Putty to print in ORANGE coloured letters, send the following string : "\033[38;5;208m"                                       *
 *                                                                                                                                  *
 * \033[ : escape code                                                                                                              *
 * 38;   : foreground, use 48 for background                                                                                        *
 * 5;    : escape mode                                                                                                              *
 * 208   : colour to use : Orange, calculated as follows : 16 + (36 X Red = 5) + (6 X Green = 2) + (Blue = 0)                       *
 *        where Red Green and Blue ranges from 0 to 5                                                                               *
 * m     : end of escape code                                                                                                       *
 \**********************************************************************************************************************************/
#define print_WHITE             "\033[38;2;255;255;255m"  //"\033[38;5;231m"
#define print_BLACK             "\033[38;2;0;0;0m"
#define print_RED               "\033[38;2;255;0;0m"      //"\033[38;5;196m"
#define print_ORANGE            "\033[38;2;255;127;0m"    //"\033[38;5;208m"
#define print_YELLOW            "\033[38;2;255;255;0m"    //"\033[38;5;226m"
#define print_GREEN             "\033[38;2;0;255;0m"      //"\033[38;5;046m"
#define print_BLUE              "\033[38;2;0;0;255m"      //"\033[38;5;021m"
#define print_INDIGO            "\033[38;2;75;0;130m"     //"\033[38;5;055m"
#define print_VIOLET            "\033[38;2;148;0;211m"    //"\033[38;5;128m"

#define print_WHITE_Background  "\033[48;2;255;255;255m"  //"\033[38;5;231m"
#define print_BLACK_Background  "\033[48;2;0;0;0m"
#define print_RED_Background    "\033[48;2;255;0;0m"      //"\033[38;5;196m"
#define print_ORANGE_Background "\033[48;2;255;127;0m"    //"\033[38;5;208m"
#define print_YELLOW_Background "\033[48;2;255;255;0m"    //"\033[38;5;226m"
#define print_GREEN_Background  "\033[48;2;0;255;0m"      //"\033[38;5;046m"
#define print_BLUE_Background   "\033[48;2;0;0;255m"      //"\033[38;5;021m"
#define print_INDIGO_Background "\033[48;2;75;0;130m"     //"\033[38;5;055m"
#define print_VIOLET_Background "\033[48;2;148;0;211m"    //"\033[38;5;128m"

#define clrscr                  "\033c"   //"\033[2J"
#define cursor_move_home        "\033[H" // can also do : "\033[12,23H" to move to row 12, column 23
//"\033[150C" Move cursor 150 positions right
//"\033[270D" Move cursor 270 positions left


 /**********************************************************************************************************************************\
 * Function prototypes                                                                                                              *
 \**********************************************************************************************************************************/
uint16_t format_terminal_clrscr_into_string(uint8_t * formatted_string, uint16_t formatted_string_length);

uint16_t format_values_into_rainbow_seismograph_line(uint8_t * formatted_string, uint16_t formatted_string_length, uint16_t value1, uint16_t value2, uint16_t value3, uint16_t value4, uint16_t value5, uint16_t value6 );

uint16_t format_values_into_rainbow_string(uint8_t * formatted_string, uint16_t formatted_string_length, int32_t number, int32_t threshold, int32_t value1, int32_t value2, int32_t value3, int32_t value4, int32_t value5, int32_t value6 );

uint16_t format_svn_and_compiler_stuff_into_string(uint8_t * formatted_string, uint16_t formatted_string_length);
