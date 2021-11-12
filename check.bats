# ------------------------------------------------------------------------------
# TESTS FOR CESAR APPLICATION
#
# ⚠️ Note that the program replace '\n' by white space while reading and writing for managing lines with more than 80 characters
# ⚠️ Tests passed locally but not on gitlab for some reasons🤷‍♂️…
# ------------------------------------------------------------------------------
# CONSTANTS
examples_folder=examples
prog=cesar
err_msg_args="✗ Error, please insert arguments to the program!…"
err_msg_file_empty="✗ Error, the file ☞ examples/empty.txt passed to the program is empty!…"
err_msg_file_doesnt_exist="✗ Error, the input file ☞ whatever.txt doesn't exist!…"

# TESTS
@test "With no argument, show error message" {
    run ./$prog
    [ "$status" -eq 1 ]
    [ "${lines[0]}" = "$err_msg_args" ]
}

@test "Input file is empty, show error message" {
    run ./$prog $examples_folder/empty.txt $examples_folder/output.txt
    [ "$status" -eq 2 ]
    [ "${lines[0]}" = "$err_msg_file_empty" ]
}

@test "Input file containing only empty lines, show error message" {
    run ./$prog $examples_folder/empty-lines.txt $examples_folder/output.txt
    [ "$status" -eq 0 ]
    [ "${lines[7]}" = " " ]
}

@test "Input file doesn't exist, show error message" {
    run ./$prog whatever.txt $examples_folder/output.txt
    [ "$status" -eq 3 ]
    [ "${lines[0]}" = "$err_msg_file_doesnt_exist" ]
}

@test "Input file original content reading, with an empty line" {
    run ./$prog $examples_folder/test-1.txt $examples_folder/output.txt
    [ "$status" -eq 0 ]
    [ "${lines[7]}" = "Door, frpphqw fd yd? CD cd " ]
    [ "${lines[11]}" = "abcvdefghijklmnopqrstuvwxyz !@# " ]
    [ "${lines[15]}" = " " ]
    [ "${lines[19]}" = "ABCDEFGHIJKLMNOPQRSTUVWXYZ $%^" ]
}

@test "Input file translation, with an empty line" {
    run ./$prog $examples_folder/test-1.txt $examples_folder/output.txt
    [ "$status" -eq 0 ]
    [ "${lines[9]}" = "Allo, comment ca va? ZA za " ]
    [ "${lines[13]}" = "xyzsabcdefghijklmnopqrstuvw !@# " ]
    [ "${lines[17]}" = " " ]
    [ "${lines[21]}" = "XYZABCDEFGHIJKLMNOPQRSTUVW $%^" ]
}

@test "Input file original content reading, with > 80 characters line" {
    run ./$prog $examples_folder/bigline.txt $examples_folder/output.txt
    [ "$status" -eq 0 ]
    [ "${lines[7]}" = "sdaffasasdsajhfjsafjsldkjsalfjalfhlasfjsalkfjaslkfjaslfjsalkfjfkldasfasfsfaallo" ]
    [ "${lines[11]}" = "toiOUI " ]
    [ "${lines[15]}" = "En effet, cest vrai etc... blablablabla YEAH" ]

}

@test "Input file translation, with > 80 characters line" {
    run ./$prog $examples_folder/bigline.txt $examples_folder/output.txt
    [ "$status" -eq 0 ]
    [ "${lines[9]}" = "paxccxpxpapxgecgpxcgpiahgpxicgxiceixpcgpxihcgxpihcgxpicgpxihcgchiaxpcxpcpcxxiil" ]
    [ "${lines[13]}" = "qlfLRF " ]
    [ "${lines[17]}" = "Bk bccbq, zbpq soxf bqz... yixyixyixyix VBXE" ]
}
