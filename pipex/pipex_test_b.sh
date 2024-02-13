# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    pipex_test_b.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 10:35:45 by dwayenbo          #+#    #+#              #
#    Updated: 2024/02/12 10:35:46 by dwayenbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
# Reset
Color_Off='\033[0m'       # Text Reset

# Regular Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

# Bold
BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White

# Underline
UBlack='\033[4;30m'       # Black
URed='\033[4;31m'         # Red
UGreen='\033[4;32m'       # Green
UYellow='\033[4;33m'      # Yellow
UBlue='\033[4;34m'        # Blue
UPurple='\033[4;35m'      # Purple
UCyan='\033[4;36m'        # Cyan
UWhite='\033[4;37m'       # White

# Background
On_Black='\033[40m'       # Black
On_Red='\033[41m'         # Red
On_Green='\033[42m'       # Green
On_Yellow='\033[43m'      # Yellow
On_Blue='\033[44m'        # Blue
On_Purple='\033[45m'      # Purple
On_Cyan='\033[46m'        # Cyan
On_White='\033[47m'       # White

# High Intensity
IBlack='\033[0;90m'       # Black
IRed='\033[0;91m'         # Red
IGreen='\033[0;92m'       # Green
IYellow='\033[0;93m'      # Yellow
IBlue='\033[0;94m'        # Blue
IPurple='\033[0;95m'      # Purple
ICyan='\033[0;96m'        # Cyan
IWhite='\033[0;97m'       # White

# Bold High Intensity
BIBlack='\033[1;90m'      # Black
BIRed='\033[1;91m'        # Red
BIGreen='\033[1;92m'      # Green
BIYellow='\033[1;93m'     # Yellow
BIBlue='\033[1;94m'       # Blue
BIPurple='\033[1;95m'     # Purple
BICyan='\033[1;96m'       # Cyan
BIWhite='\033[1;97m'      # White

# High Intensity backgrounds
On_IBlack='\033[0;100m'   # Black
On_IRed='\033[0;101m'     # Red
On_IGreen='\033[0;102m'   # Green
On_IYellow='\033[0;103m'  # Yellow
On_IBlue='\033[0;104m'    # Blue
On_IPurple='\033[0;105m'  # Purple
On_ICyan='\033[0;106m'    # Cyan
On_IWhite='\033[0;107m'   # White



printf "${BIYellow}"
echo "Removing previous logs..."
rm -rf logs
mkdir -p logs/valgrind logs/outfiles logs/infiles logs/timer_results
echo "Starting test..."
#STANDARD TEST
printf "${BIBlue}"
echo "Testing ./pipex_bonus Makefile \"hexdump\" \"cat -e\" \"cat -e\" outfile"
valgrind --track-fds=yes --trace-children=yes ./pipex_bonus Makefile "hexdump" "cat -e" "cat -e" ./logs/outfiles/outfile 2> logs/valgrind/vg_1
echo "Return value :$?" >> ./logs/outfiles/outfile
printf "${IWhite}"
echo "Test completed, for valgrind output -> logs/valgrind/vg_1"
# TEST_BAD_FUNCTION
printf "${BIBlue}"
echo "Testing ./pipex_bonus Makefile \"cat -e\" \"wrongbin\" outfile_err"
valgrind --track-fds=yes --trace-children=yes ./pipex_bonus Makefile "cat -e" "wrongbin" ./logs/outfiles/outfile_err 2> logs/valgrind/vg_err
echo "Return value :$?" >> ./logs/outfiles/outfile_err
printf "${IWhite}"
echo "Test completed, for valgrind output -> logs/valgrind/vg_err"
# TEST_NO_INFILE
printf "${BIBlue}"
echo "Testing ./pipex_bonus no_infile \"hexdump\" \"cat -e\" outf_no_infile"
valgrind --track-fds=yes --trace-children=yes ./pipex_bonus no_infile "hexdump" "cat -e" ./logs/outfiles/outf_no_infile 2> logs/valgrind/vg_no_infile
echo "Return value :$?" >> ./logs/outfiles/outf_no_infile
printf "${IWhite}"
echo "Test completed, for valgrind output -> logs/valgrind/vg_no_infile"
# TEST_INFILE_NO_READ
printf "${BIBlue}"
echo "Creating infile with \"blablabla\" in it and chmod 222..."
echo "blablabla" > ./logs/infiles/infile_no_r && chmod 222 ./logs/infiles/infile_no_r
echo "Testing ./pipex_bonus infile_no_r \"hexdump\" \"cat -e\" outf_in_no_r"
valgrind --track-fds=yes --trace-children=yes ./pipex_bonus ./logs/infiles/infile_no_r "hexdump" "cat -e" ./logs/outfiles/outf_in_no_r 2> logs/valgrind/vg_outf_in_no_r
echo "Return value :$?" >> ./logs/outfiles/outf_in_no_r
printf "${IWhite}"
echo "Test completed, for valgrind output -> logs/valgrind/vg_outf_in_no_r"
# TEST_OUTFILE_NO_WRITE
printf "${BIBlue}"
echo "Creating outfile with chmod 444..."
touch ./logs/outfiles/outf_no_w && chmod 444 ./logs/outfiles/outf_no_w
echo "Testing ./pipex_bonus Makefile \"hexdump\" \"cat -e\" outf_no_w"
valgrind --track-fds=yes --trace-children=yes ./pipex_bonus Makefile "hexdump" "cat -e" ./logs/outfiles/outf_no_w 2> logs/valgrind/vg_outf_no_w
printf "${IWhite}"
echo "Test completed, for valgrind output -> logs/valgrind/vg_outf_no_w"
#TEST_SLEEP_2_3
printf "${BIBlue}"
echo "Testing ./pipex_bonus Makefile \"sleep 2\" \"sleep 3\" outf_sleep_2_3"
valgrind --track-fds=yes --trace-children=yes ./pipex_bonus Makefile "sleep 2" "sleep 3" ./logs/outfiles/outf_sleep_2_3 2> logs/valgrind/vg_outf_sleep_2_3
{ time ./pipex_bonus Makefile "sleep 2" "sleep 3" /dev/null; } 2> ./logs/timer_results/timer_2_3
echo "Return value :$?" >> ./logs/outfiles/outf_sleep_2_3
printf "${IWhite}"
echo "Test completed, for valgrind output -> logs/valgrind/vg_outf_sleep_2_3"
#TEST_SLEEP_3_2
printf "${BIBlue}"
echo "Testing ./pipex_bonus Makefile \"sleep 3\" \"sleep 2\" \"sleep 1\" outf_sleep_3_2_1"
valgrind --track-fds=yes --trace-children=yes ./pipex_bonus Makefile "sleep 3" "sleep 2" "sleep 1" ./logs/outfiles/outf_sleep_3_2_1 2> logs/valgrind/vg_outf_sleep_3_2_1
{ time ./pipex_bonus Makefile "sleep 3" "sleep 2" /dev/null; } 2> ./logs/timer_results/timer_3_2_1
echo "Return value :$?" >> ./logs/outfiles/outf_sleep_3_2_1
printf "${IWhite}"
echo "Test completed, for valgrind output -> logs/valgrind/vg_outf_sleep_3_2_1"
#TIMEOUT TEST
printf "${BIBlue}"
echo "Testing ./pipex_bonus /dev/random \"cat\" \"hexdump -C\" \"head -5\" outf_timeout"
valgrind --track-fds=yes --trace-children=yes ./pipex_bonus /dev/random "cat" "hexdump -C" "head -5" ./logs/outfiles/outf_timeout 2> logs/valgrind/vg_outf_timeout
echo "Return value :$?" >> ./logs/outfiles/outf_timeout
printf "${IWhite}"
echo "Test completed, for valgrind output -> logs/valgrind/vg_outf_timeout (LEAKS ARE EXPECTED)"
#HERE_DOC TEST with lim
printf "${BIGreen}"
echo "All Done !!"
printf "${BIRed}"
echo "Don't forget to test here_doc ;)"