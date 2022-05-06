int stringcompare(char string[], char string1[]) {
    int i = 0;
    while (string[i] != '\0' || string1[i] != '\0') {
        if (string[i] != string1[i]) {
            return 0;

        }
        return 1;
    }
}
