rm test.pl
echo ":- begin_tests(lists)." >> test.pl
echo ":- use_module(library(lists))." >> test.pl
cat ass3.pl  query.pl >> test.pl
echo ":- end_tests(lists)." >> test.pl
