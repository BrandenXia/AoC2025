define(`parse_', `patsubst(`$1', `R\([0-9]+\)
', `EAT(\1)')')dnl
define(`parse', `patsubst(parse_(`$1'), `L\([0-9]+\)
', `SHIT(\1)')')dnl
dnl
define(`input', include(`input.txt'))dnl
define(`parsed', parse(input))dnl
define(`dial', 50)dnl
define(`passwd', 0)dnl
define(`check', `ifelse(eval(dial == 0), 1, `define(`passwd', incr(passwd))',)')dnl
define(`EAT', `define(`dial', eval( ((dial + `$1') % 100 + 100) % 100 ))check()')dnl
define(`SHIT', `define(`dial', eval( ((dial - `$1') % 100 + 100) % 100 ))check()')dnl
parsed dnl
passwd
