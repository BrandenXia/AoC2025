define(`parse_', `patsubst(`$1', `R\([0-9]+\)
', `EAT(\1)')')dnl
define(`parse', `patsubst(parse_(`$1'), `L\([0-9]+\)
', `SHIT(\1)')')dnl
dnl
define(`input', include(`input.txt'))dnl
define(`parsed', parse(input))dnl
define(`dial', 50)dnl
define(`passwd', 0)dnl
define(`EAT', `define(`prev', dial)define(`tmp', eval(dial + `$1'))define(`dial', eval( (tmp % 100 + 100) % 100 ))define(`passwd', eval(passwd + (prev + `$1') / 100))')dnl
define(`SHIT', `define(`prev', dial)define(`tmp', eval(dial - `$1'))define(`dial', eval( (tmp % 100 + 100) % 100 ))define(`passwd', eval(passwd + ((100 - prev) % 100 + `$1') / 100))')dnl
parsed dnl
passwd
