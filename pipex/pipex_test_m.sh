# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    pipex_test_m.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 10:35:54 by dwayenbo          #+#    #+#              #
#    Updated: 2024/02/12 10:35:55 by dwayenbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
YELLOW='\033[1;33m'
WHITE='\033[0m'
GREEN='\033[0;32m'

printf "${YELLOW}"
echo "Removing previous logs..."
rm -rf logs
mkdir -p logs/valgrind logs/outfiles logs/infiles logs/timer_results
echo "Starting test..."
#STANDARD TEST
printf "${GREEN}"
echo "Testing ./pipex Makefile \"hexdump\" \"cat -e\" outfile"
valgrind --track-fds=yes --trace-children=yes ./pipex Makefile "hexdump" "cat -e" ./logs/outfiles/outfile 2> logs/valgrind/vg_1
echo "Return value :$?" >> ./logs/outfiles/outfile
printf "${WHITE}"
echo "Test completed, for valgrind output -> logs/valgrind/vg_1"
# TEST_BAD_FUNCTION
printf "${GREEN}"
echo "Testing ./pipex Makefile \"cat -e\" \"wrongbin\" outfile_err"
valgrind --track-fds=yes --trace-children=yes ./pipex Makefile "cat -e" "wrongbin" ./logs/outfiles/outfile_err 2> logs/valgrind/vg_err
echo "Return value :$?" >> ./logs/outfiles/outfile_err
printf "${WHITE}"
echo "Test completed, for valgrind output -> logs/valgrind/vg_err"
# TEST_NO_INFILE
printf "${GREEN}"
echo "Testing ./pipex no_infile \"hexdump\" \"cat -e\" outf_no_infile"
valgrind --track-fds=yes --trace-children=yes ./pipex no_infile "hexdump" "cat -e" ./logs/outfiles/outf_no_infile 2> logs/valgrind/vg_no_infile
echo "Return value :$?" >> ./logs/outfiles/outf_no_infile
printf "${WHITE}"
echo "Test completed, for valgrind output -> logs/valgrind/vg_no_infile"
# TEST_INFILE_NO_READ
printf "${GREEN}"
echo "Creating infile with \"blablabla\" in it and chmod 222..."
echo "blablabla" > ./logs/infiles/infile_no_r && chmod 222 ./logs/infiles/infile_no_r
echo "Testing ./pipex infile_no_r \"hexdump\" \"cat -e\" outf_in_no_r"
valgrind --track-fds=yes --trace-children=yes ./pipex ./logs/infiles/infile_no_r "hexdump" "cat -e" ./logs/outfiles/outf_in_no_r 2> logs/valgrind/vg_outf_in_no_r
echo "Return value :$?" >> ./logs/outfiles/outf_in_no_r
printf "${WHITE}"
echo "Test completed, for valgrind output -> logs/valgrind/vg_outf_in_no_r"
# TEST_OUTFILE_NO_WRITE
printf "${GREEN}"
echo "Creating outfile with chmod 444..."
touch ./logs/outfiles/outf_no_w && chmod 444 ./logs/outfiles/outf_no_w
echo "Testing ./pipex Makefile \"hexdump\" \"cat -e\" outf_no_w"
valgrind --track-fds=yes --trace-children=yes ./pipex Makefile "hexdump" "cat -e" ./logs/outfiles/outf_no_w 2> logs/valgrind/vg_outf_no_w
printf "${WHITE}"
echo "Test completed, for valgrind output -> logs/valgrind/vg_outf_no_w"
#TEST_SLEEP_2_3
printf "${GREEN}"
echo "Testing ./pipex Makefile \"sleep 2\" \"sleep 3\" outf_sleep_2_3"
valgrind --track-fds=yes --trace-children=yes ./pipex Makefile "sleep 2" "sleep 3" ./logs/outfiles/outf_sleep_2_3 2> logs/valgrind/vg_outf_sleep_2_3
{ time ./pipex Makefile "sleep 2" "sleep 3" /dev/null; } 2> ./logs/timer_results/timer_2_3
echo "Return value :$?" >> ./logs/outfiles/outf_sleep_2_3
printf "${WHITE}"
echo "Test completed, for valgrind output -> logs/valgrind/vg_outf_sleep_2_3"
#TEST_SLEEP_3_2
printf "${GREEN}"
echo "Testing ./pipex Makefile \"sleep 3\" \"sleep 2\" outf_sleep_3_2"
valgrind --track-fds=yes --trace-children=yes ./pipex Makefile "sleep 3" "sleep 2" ./logs/outfiles/outf_sleep_3_2 2> logs/valgrind/vg_outf_sleep_3_2
{ time ./pipex Makefile "sleep 3" "sleep 2" /dev/null; } 2> ./logs/timer_results/timer_3_2
echo "Return value :$?" >> ./logs/outfiles/outf_sleep_3_2
printf "${WHITE}"
echo "Test completed, for valgrind output -> logs/valgrind/vg_outf_sleep_3_2"
#TIMEOUT TEST
printf "${GREEN}"
echo "Testing ./pipex /dev/random \"cat\" \"head -5\" outf_timeout"
valgrind --track-fds=yes --trace-children=yes ./pipex /dev/random "cat" "head -5" ./logs/outfiles/outf_timeout 2> logs/valgrind/vg_outf_timeout
echo "Return value :$?" >> ./logs/outfiles/outf_timeout
printf "${WHITE}"
echo "Test completed, for valgrind output -> logs/valgrind/vg_outf_timeout (LEAKS ARE EXPECTED)"
