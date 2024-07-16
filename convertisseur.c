#include<stdio.h>  // pour: input & output
#include<stdlib.h> // pour: exit(0)
#include<curses.h>  // pour: getch()
#include<ctype.h>  // pour: isdigit()
#include<math.h>   // pour: pow(2,0)
#include<string.h> // pour: strlen()

// Definitions des constantes je m'en sert pour l'Hexa
#define ENTER 13
#define TAB 9
#define BKSP 8

void welcomeScreen(void);    // page d'intro + choix
void exitScreen(void);       // fin de programme + credit
void screenCleaner(void);    // vider l'entrée et la sortie standard
void userInput(int);         // prends l'entrée de l'utilisateur et la valide
int digitChecker(int, int);  // valide tout les chiffres de l'entrée utilisateurs
void conversion_Title(void); // page titre pour toutes les conversions
void tryAgain(int);          // fenêtre try Again

void binary_decimal(long long);
void binary_octal(long long);
void binary_hexadecimal(long long);

void decimal_binary(int);
void decimal_octal(int);
void decimal_hexadecimal(int);

void octal_binary(long long);
void octal_decimal(long long);
void octal_hexadecimal(long long);

void hexadecimal_binary(char []);
void hexadecimal_octal(char []);
void hexadecimal_decimal(char []);

void main()
{
    welcomeScreen();
}

// Intro
void welcomeScreen()
{
    int choice;

label1:
    screenCleaner();
    printf("-------------------------------------------\n");
    printf(">>> Welcome to Number System Converter <<< \n");
    printf("-------------------------------------------\n\n");

    printf(">> Select Conversion Type: \n");
    printf("> 1. Binary Conversion \n");
    printf("> 2. Decimal Conversion \n");
    printf("> 3. Octal Conversion \n");
    printf("> 4. Hexadecimal Conversion \n");
    printf("> 5. Exit the Program \n\n");
    printf("Enter the number & Hit ENTER: ");
    scanf("%d", &choice);

    // choix de la conversion
    switch(choice)
    {
        case 1:
            userInput(1);
            break;
        case 2:
            userInput(2);
            break;
        case 3:
            userInput(3);
            break;
        case 4:
            userInput(4);
            break;
        case 5:
            exitScreen();
            break;
        default:
            printf("\nError: the number must be between 1 to 5.\n");
            printf("Press any key to continue... \n");
            getch();
            goto label1;
    }
}

// (page de crédit)
void exitScreen()
{
    screenCleaner();
    printf("-------------------------------------------\n");
    printf(" >>> Creator : Tonguechaude <<< \n");
    printf("-------------------------------------------\n\n");

    printf("> GitHub: https://github.com/Tonguechaude \n");
    printf("> LinkedIn: https://www.linkedin.com/in/ \n\n");

    exit(0);  // exit() pour quitter proprement
}

void screenCleaner()
{
   #ifdef _WIN32
    system("cls"); // windows
   #else
    system("clear"); // Unix/Linux
   #endif

}

void userInput(int choice)
{
    screenCleaner();

    if(choice == 1) // Code pour le Binaire
    {
        long long bi;
        int flag = 0;

        printf("Enter the binary: ");
        scanf("%ld", &bi);

        flag = digitChecker(bi, choice);

        if(flag == 1)
        {
            printf("\nError: Binary can only have the digits 0, 1. \n");
            printf("Press any key to continue... \n");
            getch();
            welcomeScreen();
        }
        else
        {
            conversion_Title();
            binary_decimal(bi);
            binary_octal(bi);
            binary_hexadecimal(bi);
            tryAgain(choice);
        }
    }
    else if(choice == 2)  // Code pour le Decimal
    {
        long long deci;
        int flag = 0;

        printf("Enter the decimal: ");
        scanf("%ld", &deci);

        if(deci > 0)
            flag = digitChecker(deci, choice);
        else
            flag = 1;

        if(flag == 1)
        {
            printf("\nError: Decimal number can't be negative. \n");
            printf("Press any key to continue... \n");
            getch();
            welcomeScreen();
        }
        else
        {
            conversion_Title();
            decimal_binary(deci);
            decimal_octal(deci);
            decimal_hexadecimal(deci);
            tryAgain(choice);
        }
    }
    else if(choice == 3)  // Code pour l'Octal
    {
        long long octal;
        int flag = 0;

        printf("Enter the octal: ");
        scanf("%ld", &octal);

        flag = digitChecker(octal, choice);

        if(flag == 1)
        {
            printf("\nError: Octal digits can only be between 0 to 7. \n");
            printf("Press any key to continue... \n");
            getch();
            welcomeScreen();
        }
        else
        {
            conversion_Title();
            octal_binary(octal);
            octal_decimal(octal);
            octal_hexadecimal(octal);
            tryAgain(choice);
        }
    }
    else if(choice == 4)  // Code pour l'Hexadecimal
        {
            char hexa[50];
            int flag = 0;

            printf("Enter the hexadecimal: ");
            scanf("%s", hexa);

            for(int j = 0; hexa[j] != '\0'; j++)
            {
                if(!isxdigit(hexa[j]))
                {
                    flag = 1;
                    break;
                }
            }

            if(flag == 1)
            {
                printf("\n\nError: Hexadecimal digits can only be between 0 to 9 & A to F. \n");
                printf("Press any key to continue... \n");
                getchar(); // Pour capturer le retour après l'erreur
                welcomeScreen();
            }
            else
            {
                printf("\n");
                conversion_Title();
                hexadecimal_binary(hexa);
                hexadecimal_octal(hexa);
                hexadecimal_decimal(hexa);
                tryAgain(choice);
            }
        }
    else  // Normalement ca doit être très rare
        printf("\n>> Unexpected Error occured. Report to program Administrator << \n");
}

// fonction de validation de chaque chiffre en accord avec les conditions de conversions
int digitChecker(int num, int choice)
{
    long long rem;
    long int temp=0, flag=0;
    temp = num;

        while(temp != 0)
        {
            rem = temp % 10;

            if((rem == 0 || rem == 1) && choice == 1) // binary, choice = 1
                temp = temp / 10;
            else if(rem >= 0 && rem <= 9 && choice == 2) // decimal, choice = 2
                temp = temp / 10;
            else if(rem >= 0 && rem <=7 && choice == 3) // octal, choice = 3
                temp = temp / 10;
            else
            {
                flag = 1;
                break;
            }
        }
    return flag;
}

// titre pour les sorties de toutes les conversions
void conversion_Title()
{
    printf("\n---------------------------\n");
    printf(">>> Conversion Results <<< \n");
    printf("---------------------------\n");
}

// fenêtre try Again
void tryAgain(int choice)
{
    char ch;

    printf("\n\nDo you want to try again [y/N]: ");
    scanf(" %c", &ch);

    switch (ch)
    {
        case 'Y':
        case 'y':
            userInput(choice);
            break;
        case 'N':
        case 'n':
            welcomeScreen();
            break;
        default:
            printf("\nError: invalid input. \n");
            printf("Press any key to continue... \n");
            getch();
            welcomeScreen();
    }
}

// fonctions conversions binaire -> décimal
void binary_decimal(long long bi)
{
    long rem,sum=0;
    int i=0;

    while(bi!=0)
    {
        rem = bi % 10;
        bi /= 10;
        sum += rem * pow(2,i);
        i++;
    }

    printf("\nDecimal Number: %d",sum);
}

// fonctions conversions binaire -> octal
void binary_octal(long long bi)
{
    long long rem,sum=0,remain[100];
    int i=0, len=0;
    while(bi!=0)
    {
        rem=bi%10;
        bi=bi/10;
        sum=sum+rem*pow(2,i);
        i++;
    }
    i=0;
    while(sum!=0)
    {
        remain[i]=sum%8;
        sum=sum/8;
        i++;
        len++;
    }

    printf("\nOctal Number: ");
    for(i=len-1;i>=0;i--)
    {
        printf("%d",remain[i]);
    }
}

// fonctions conversions binaire -> hexadécimal
void binary_hexadecimal(long long bi)
{
    long long rem, sum=0,remain[100];
    int i=0, len=0;

    while(bi!=0)
    {
        rem=bi%10;
        bi=bi/10;
        sum=sum+rem*pow(2,i);
        i++;
    }
    i=0;
    while(sum!=0)
    {
        remain[i]=sum%16;
        sum=sum/16;
        i++;
        len++;
    }

    printf("\nHexa-Decimal Number: ");
    for(i=len-1;i>=0;i--)
    {
        switch(remain[i])
        {
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            default:
                printf("%d",remain[i]);
        }
    }
}

// fonctions conversions décimal -> binaire
void decimal_binary(int deci)
{
    char bin[65];
    int rem, i = 0;

    if (deci == 0) {
        printf("\nBinary Number: 0");
        return;
    }

    while (deci != 0)
    {
        rem = deci % 2;
        deci /= 2;
        bin[i++] = rem + '0';  // Convertir le bit en caractère '0' ou '1'
    }

    bin[i] = '\0';

    // Inverser la chaîne pour obtenir le binaire dans le bon ordre
    for (int j = 0; j < i / 2; j++) {
        char temp = bin[j];
        bin[j] = bin[i - j - 1];
        bin[i - j - 1] = temp;
    }

    printf("\nBinary Number: %s", bin);
}

// fonctions conversions décimal -> octal
void decimal_octal(int deci)
{
    long long octal = 0;
    int rem, i = 1;

    while (deci != 0)
    {
        rem = deci % 8;
        deci /= 8;
        octal += rem * i;
        i *= 10;
    }

    printf("\nOctal Number: ");
    printf("%lld", octal);
}

// fonctions conversions décimal -> hexadécimal
void decimal_hexadecimal(int deci)
{
    long long rem[50];
    int i = 0, len = 0;

    while(deci!=0)
    {
        rem[i]=deci%16;
        deci=deci/16;
        i++;
        len++;
    }

    printf("\nHexa-Decimal Number: ");
    for(i=len-1;i>=0;i--)
    {
        switch(rem[i])
        {
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            default:
                printf("%d",rem[i]);
        }
    }
}

// fonctions conversions octal -> binaire
void octal_binary(long long oct)
{
    long long rem[50], decimal=0, num, ans;
    int len=0, i=0;

    while(oct!=0)
    {
        ans=oct % 10;
        decimal = decimal + ans * pow(8,i);
        i++;
        oct = oct/10;
    }

    i=0;
    do
    {
        rem[i]=decimal%2;
        decimal=decimal/2;
        i++;
        len++;
    }
    while(decimal!=0);

    printf("\nBinary Number: ");
    for(i=len-1;i>=0;i--)
    {
        printf("%d",rem[i]);
    }
}

// fonctions conversions octal -> décimal
void octal_decimal(long long oct)
{
    int decimal=0,i=0,num,ans;

    while(oct!=0)
    {
        ans=oct % 10;
        decimal = decimal + ans * pow(8,i);
        i++;
        oct = oct/10;
    }
    printf("\nDecimal Number: %d",decimal);
}

// fonctions conversions octal -> hexadécimal
void octal_hexadecimal(long long oct)
{
    long long rem[50], decimal=0, num, ans=0;
    int len=0, i=0;

    while(oct!=0)
    {
        ans=oct % 10;
        decimal = decimal + ans * pow(8,i);
        i++;
        oct = oct/10;
    }

    i=0;
    while(decimal!=0)
    {
        rem[i]=decimal%16;
        decimal=decimal/16;
        i++;
        len++;
    }

    printf("\nHexa-Decimal Number: ");

    for(i=len-1;i>=0;i--)
    {
        switch(rem[i])
        {
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            default:
                printf("%d",rem[i]);
        }
    }
}

// fonctions conversions hexadécimal -> binaire
void hexadecimal_binary(char hexa[])
{
    int i=0;

    printf("\nBinary Number: ");

    for(i=0;i<strlen(hexa);i++)
    {
        switch (hexa[i])
        {
            case '0':
                printf("0000");
                break;
            case '1':
                printf("0001");
                break;
            case '2':
                printf("0010");
                break;
            case '3':
                printf("0011");
                break;
            case '4':
                printf("0100");
                break;
            case '5':
                printf("0101");
                break;
            case '6':
                printf("0110");
                break;
            case '7':
                printf("0111");
                break;
            case '8':
                printf("1000");
                break;
            case '9':
                printf("1001");
                break;
            case 'A':
            case 'a':
                printf("1010");
                break;
            case 'B':
            case 'b':
                printf("1011");
                break;
            case 'C':
            case 'c':
                printf("1100");
                break;
            case 'D':
            case 'd':
                printf("1101");
                break;
            case 'E':
            case 'e':
                printf("1110");
                break;
            case 'F':
            case 'f':
                printf("1111");
                break;
            default:
                printf("\n Invalid hexa digit %c ", hexa[i]);
        }
    }
}

// fonctions conversions hexadécimal -> octal
void hexadecimal_octal(char hexa[])
{
    long long num=0,power=0,decimal=0,rem[100];
    int i, len;

    for(i=strlen(hexa)-1;i>=0;i--)
    {
        if(hexa[i]=='A'||hexa[i]=='a')
            num=10;
        else if(hexa[i]=='B'||hexa[i]=='b')
            num=11;
        else if(hexa[i]=='C'||hexa[i]=='c')
            num=12;
        else if(hexa[i]=='D'||hexa[i]=='d')
            num=13;
        else if(hexa[i]=='E'||hexa[i]=='e')
            num=14;
        else if(hexa[i]=='F'||hexa[i]=='f')
            num=15;
        else
            num=hexa[i]-48;

        decimal=decimal+num*pow(16,power);
        power++;
    }

    i=0,len=0;
    while(decimal!=0)
    {
        rem[i]=decimal%8;
        decimal=decimal/8;
        i++;
        len++;
    }

    printf("\nOctal Number: ");
    for(i=len-1;i>=0;i--)
    {
        printf("%d",rem[i]);
    }
}

// fonctions conversions hexadécimal -> décimal
void hexadecimal_decimal(char hexa[])
{
    long long num=0,power=0,decimal=0;
    int i;

    for(i=strlen(hexa)-1;i>=0;i--)
    {
        if(hexa[i]=='A'||hexa[i]=='a')
            num=10;
        else if(hexa[i]=='B'||hexa[i]=='b')
            num=11;
        else if(hexa[i]=='C'||hexa[i]=='c')
            num=12;
        else if(hexa[i]=='D'||hexa[i]=='d')
            num=13;
        else if(hexa[i]=='E'||hexa[i]=='e')
            num=14;
        else if(hexa[i]=='F'||hexa[i]=='f')
            num=15;
        else
            num=hexa[i]-48;

        decimal=decimal+num*pow(16,power);
        power++;
    }
    printf("\nDecimal Number: %d",decimal);
}
