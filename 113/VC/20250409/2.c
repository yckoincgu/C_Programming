    #include <stdio.h>
    #include <locale.h>

int main()
{
    char s[25]; 
    //char x = '\"';  

    printf("Enter a string like hello world:  "); 
    scanf("%s", s);

    printf("The scanf function reads ∧ %s\n", s);


    
 
        setlocale(LC_ALL, ""); // Set locale for UTF-8
    
        char input[10]; // Array to store input (adjust size as needed)
        printf("Enter a character (including ∧): ");
        scanf("%9s", input); // Read up to 9 characters to prevent buffer overflow.  Use %s for char array input.
    
        printf("Integer values of the bytes entered:\n");
        for (int i = 0; input[i] != '\0'; i++) {
            printf("input[%d] = %d (0x%X)\n", i, (unsigned char)input[i], (unsigned char)input[i]);
            //  %d for decimal, %x for hexadecimal
            //  Important to cast to unsigned char to get the correct positive integer value.

    
        return 0;
    }
    


    return 0;
}
