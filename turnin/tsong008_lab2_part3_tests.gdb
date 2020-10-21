# Test file for "Lab2_introToAVR"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

test "PINA: 0x00 => PINB: 0x04" 
setPINA 0x00
continue 5
expectPORTB 0x04 
checkResult

test "PINA: 0x01 => PINB: 0x03" 
setPINA 0x01
continue 5
expectPORTB 0x03
checkResult

test "PINA: 0x02 => PINB: 0x03" 
setPINA 0x02
continue 5
expectPORTB 0x03
checkResult

test "PINA: 0x03 => PINB: 0x02" 
setPINA 0x03
continue 5
expectPORTB 0x02
checkResult

test "PINA: 0x04 => PINB: 0x03"
setPINA 0x03
contiinue 5
expectPORTB 0x03 
checkResult

test "PINA: 0x05 => PINB: 0x02"
setPINA 0x05
contiinue 5
expectPORTB 0x02 
checkResult

test "PINA: 0x06 => PINB: 0x02"
setPINA 0x06
contiinue 5
expectPORTB 0x02 
checkResult

test "PINA: 0x07 => PINB: 0x01"
setPINA 0x07
contiinue 5
expectPORTB 0x01 
checkResult

test "PINA: 0x08 => PINB: 0x03"
setPINA 0x08
contiinue 5
expectPORTB 0x03 
checkResult

test "PINA: 0x09 => PINB: 0x02" 
setPINA 0x09
continue 5
expectPORTB 0x02 
checkResult

test "PINA: 0x0A => PINB: 0x02" 
setPINA 0x0A
continue 5
expectPORTB 0x02
checkResult

test "PINA: 0x0B => PINB: 0x01" 
setPINA 0x0B
continue 5
expectPORTB 0x01
checkResult

test "PINA: 0x0C => PINB: 0x02" 
setPINA 0x0C
continue 5
expectPORTB 0x02
checkResult

test "PINA: 0x0D => PINB: 0x01"
setPINA 0x0D
contiinue 5
expectPORTB 0x01 
checkResult

test "PINA: 0x0E => PINB: 0x01"
setPINA 0x0E
contiinue 5
expectPORTB 0x01 
checkResult

test "PINA: 0x0F => PINB: 0x80"
setPINA 0x0F
contiinue 5
expectPORTB 0x80 
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
