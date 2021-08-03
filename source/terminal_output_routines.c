 /**********************************************************************************************************************************\
 * Title : Terminal printing support routines                                                                                       *
 *                                                                                                                                  *
 * Author : Gert van Biljon                                                                                                         *
 *                                                                                                                                  *
 * EMail : gertvb@gmail.com                                                                                                         *
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
 $Date:: 2021-05-05 16:38:06 +0200 (Wed, 05 May 2021)                                                                               $
 $Revision:: 1440                                                                                                                   $
 $URL:: https://techexplorer/svn/SVN_Repository/c/terminal_output_routines/terminal_output_routines.c                               $
 \**********************************************************************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "terminal_output_routines.h"


 /**********************************************************************************************************************************\
 * Function name : format_values_into_rainbow_seismograph_line                                                                      *
 *                                                                                                                                  *
 * Author : Gert van Biljon                                                                                                         *
 *                                                                                                                                  *
 * What do I do : I print a coloured * character for each of the 6 uint16_t values that I receive, all values on one line           *
 *                The x position of the * character varies between 0 to 255, and is based on the value / 256                        *
 *                The x position of * character is set with the VT100 escape code "\033[nC", which moves the cursor n chars         *
 *                forward/right, and backwards/left with "\033[nD"                                                                  *
 \**********************************************************************************************************************************/
uint16_t format_values_into_rainbow_seismograph_line(uint8_t * formatted_string, uint16_t formatted_string_length, uint16_t value1, uint16_t value2, uint16_t value3, uint16_t value4, uint16_t value5, uint16_t value6 )
{
    uint16_t format_length;
    format_length = snprintf(
                                (char *)formatted_string,
								formatted_string_length,
                                print_WHITE
                                "\033[0C*\033[270D"   //White left line
                                "\033[127C*\033[270D" //White centre line
                                "\033[255C*\033[270D" //White right line

                                print_RED
                                "\033[%uC*\033[270D"
                                print_ORANGE
                                "\033[%uC*\033[270D"
                                print_YELLOW
                                "\033[%uC*\033[270D"
                                print_GREEN
                                "\033[%uC*\033[270D"
                                print_BLUE
                                "\033[%uC*\033[270D"
                                print_VIOLET
                                "\033[%uC*\033[270D"
                                "\n\r",
                                value1 >> 8,
                                value2 >> 8,
                                value3 >> 8,
                                value4 >> 8,
                                value5 >> 8,
                                value6 >> 8
                                );
    return format_length;
}//uint16_t format_values_into_rainbow_seismograph_line(uint8_t * formatted_string, uint16_t formatted_string_length, uint16_t value1, uint16_t value2, uint16_t value3, uint16_t value4, uint16_t value5, uint16_t value6 )

 /**********************************************************************************************************************************\
 * Function name : format_values_into_rainbow_string                                                                                *
 *                                                                                                                                  *
 * Author : Gert van Biljon                                                                                                         *
 *                                                                                                                                  *
 * What do I do : I print the values of six variables next to each other on one line, varying the foreground/background colour      *
 *                depending on the variable's value compared to the specified threshold                                             *
 *                If the value is >= threshold, the text is coloured and the background black                                       *
 *                If the value is < threshold, the text is black and the background coloured                                        *
 \**********************************************************************************************************************************/
uint16_t format_values_into_rainbow_string( uint8_t * formatted_string,
											uint16_t formatted_string_length,
											int32_t number,
											int32_t threshold,
											int32_t value1,
											int32_t value2,
											int32_t value3,
											int32_t value4,
											int32_t value5,
											int32_t value6
											)
{
    uint16_t format_length;
    format_length = snprintf(
                                (char *)formatted_string,
								formatted_string_length,
                                print_WHITE
                                "*** "

								"%5d "

                                "*** "

                                print_BLACK

                                "%s"
                                "%6d "

                                print_BLACK_Background
                                print_WHITE
                                " * "
                                print_BLACK

                                "%s"
                                "%6d "

                                print_BLACK_Background
                                print_WHITE
                                " * "
                                print_BLACK

                                "%s"
                                "%6d "

                                print_BLACK_Background
                                print_WHITE
                                " * "
                                print_BLACK

                                "%s"
                                "%6d "

                                print_BLACK_Background
                                print_WHITE
                                " * "
                                print_BLACK

                                "%s"
                                "%6d "

                                print_BLACK_Background
                                print_WHITE
                                " * "
                                print_BLACK

                                "%s"
                                "%6d "

                                print_BLACK_Background
                                print_WHITE
                                " ***"
                                "\n\r",

								number,

                                (value1 >= threshold ? print_RED : print_RED_Background),
                                value1,

                                (value2 >= threshold ? print_ORANGE : print_ORANGE_Background),
                                value2,

                                (value3 >= threshold ? print_YELLOW : print_YELLOW_Background),
                                value3,

                                (value4 >= threshold ? print_GREEN : print_GREEN_Background),
                                value4,

                                (value5 >= threshold ? print_BLUE : print_BLUE_Background),
                                value5,

                                (value6 >= threshold ? print_VIOLET : print_VIOLET_Background),
                                value6

                            );
    return format_length;
}//uint16_t format_values_into_rainbow_string(uint8_t * formatted_string, uint16_t formatted_string_length, int64_t value1, int64_t value2, int64_t value3, int64_t value4, int64_t value5, int64_t value6, int64_t threshold )

 /**********************************************************************************************************************************\
 * Function name : format_svn_and_compiler_stuff_into_string                                                                        *
 *                                                                                                                                  *
 * Author : Gert van Biljon                                                                                                         *
 *                                                                                                                                  *
 * What do I do : Extract SVN info and format it into a decent display                                                              *
 \**********************************************************************************************************************************/
uint16_t format_svn_and_compiler_stuff_into_string(uint8_t* formatted_string, uint16_t formatted_string_length, char* SVN_Author, char* SVN_Revision, char* SVN_Date)
{
	//Go and declare these in the main program where this fonction is called from
	//#define SVN_string_lengths 75
	//volatile char SVN_Author[SVN_string_lengths] = "$Author: Gert_v_B $";
	//volatile char SVN_Revision[SVN_string_lengths] = "$Revision: 1440 $";
	//volatile char SVN_Date[SVN_string_lengths] = "$Date: 2021-05-05 16:38:06 +0200 (Wed, 05 May 2021) $";

	char SVN_String_Delimiter[] = " ";

    char * Extracted_SVN_Author_String;
    char * Extracted_SVN_Revision_String;
    char * Extracted_SVN_Date_String;
    char * Extracted_SVN_Time_String;

//Infineon XMC4500 defines for chip id.....
//    uint32_t Chip_ID[4];
//    Chip_ID[0] = (g_chipid[ 3] << 24) + (g_chipid[ 2] << 16) + (g_chipid[ 1] << 8) + g_chipid[ 0];
//    Chip_ID[1] = (g_chipid[ 7] << 24) + (g_chipid[ 6] << 16) + (g_chipid[ 5] << 8) + g_chipid[ 4];
//    Chip_ID[2] = (g_chipid[11] << 24) + (g_chipid[10] << 16) + (g_chipid[ 9] << 8) + g_chipid[ 8];
//    Chip_ID[3] = (g_chipid[15] << 24) + (g_chipid[14] << 16) + (g_chipid[13] << 8) + g_chipid[12];

    Extracted_SVN_Author_String = strtok(SVN_Author, SVN_String_Delimiter);
    Extracted_SVN_Author_String = strtok(NULL, SVN_String_Delimiter);

    Extracted_SVN_Revision_String = strtok(SVN_Revision, SVN_String_Delimiter);
    Extracted_SVN_Revision_String = strtok(NULL, SVN_String_Delimiter);

    Extracted_SVN_Date_String = strtok(SVN_Date, SVN_String_Delimiter);
    Extracted_SVN_Date_String = strtok(NULL, SVN_String_Delimiter);
    Extracted_SVN_Time_String = strtok(NULL, SVN_String_Delimiter);

    uint16_t format_length;
    format_length = snprintf(
                                (char *)formatted_string,
								formatted_string_length,
								//clrscr
								"\n\r"
                                "\n\r"
                                print_WHITE
                                "TechExplorer Development Framework\n\r"
                                //"Copyright (c) 2019-2021 TechExplorer\n\r" //© is difficult to print on the different terminals thus I use (c)
                                "\n\r"

                                print_WHITE
                                "Email : "
                                print_GREEN
                                "gertvb@gmail.com \n\r\n\r"

                                print_WHITE
                                "Subversion Author : "
                                print_RED
                                "%s"
                                "\r\n"

                                print_WHITE
                                "Subversion Revision : "
                                print_ORANGE
                                "%s"
                                "\r\n"

                                print_WHITE
                                "Subversion Date : "
                                print_YELLOW
                                "%s"
                                "\r\n"

                                print_WHITE
                                "Subversion Time : "
                                print_GREEN
                                "%s"
                                "\r\n\r\n"

                                print_WHITE
                                "Compile Date : "
                                print_BLUE
                                "%s"
                                "\r\n"

                                print_WHITE
                                "Compile Time : "
                                print_VIOLET
                                "%s"
                                print_WHITE
                                "\r\n\r\n"

                                print_WHITE
                                "GCC version : "
                                print_RED
                                "%d.%d.%d"
                                print_WHITE
                                "\r\n\r\n"
                                ,

                                //print_WHITE
                                //"XMC4500 Chip ID : "
                                //print_RED
                                //"%lu-%lu-%lu-%lu"
                                //"\r\n\r\n"
                                //,

                                Extracted_SVN_Author_String,
                                Extracted_SVN_Revision_String,
                                Extracted_SVN_Date_String,
                                Extracted_SVN_Time_String,

								__DATE__,
                                __TIME__,

                                __GNUC__,
                                __GNUC_MINOR__,
                                __GNUC_PATCHLEVEL__

                                //Chip_ID[3],
                                //Chip_ID[2],
                                //Chip_ID[1],
                                //Chip_ID[0]
                                );
    return format_length;
}//uint16_t format_svn_and_compiler_stuff_into_string(uint8_t * formatted_string, uint16_t formatted_string_length)

uint16_t format_terminal_clrscr_into_string(uint8_t * formatted_string, uint16_t formatted_string_length)
{
    uint16_t format_length;
    format_length = snprintf(
                                (char *)formatted_string,
								formatted_string_length,
                                print_WHITE
                                clrscr
                                cursor_move_home
                            );
    return format_length;
}//uint16_t format_terminal_clrscr_into_string(uint8_t * formatted_string, uint16_t formatted_string_length)
