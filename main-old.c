#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Option
{
    char  name[24];
    char  value[24];
    char  default_value[24];
    char  question[100];
} options [24];

void init_options()
{
    strcpy(options[0].value,"<location>");
    strcpy(options[0].default_value,"Earth");
    strcpy(options[0].value,options[0].default_value);
    strcpy(options[0].question,"Kur yra sis serveris?\n");

    strcpy(options[1].value,"<admin>");
    strcpy(options[1].default_value,"icemaster@localhost");
    strcpy(options[1].value,options[0].default_value);
    strcpy(options[1].question,"Koks administratoriaus el. pasto adresas?\n");

    strcpy(options[2].value,"<hostname>");
    strcpy(options[2].default_value,"localhost");
    strcpy(options[2].value,options[0].default_value);
    strcpy(options[2].question,"Koks serverio pavadinimas?\n");

    strcpy(options[3].value,"<clients>");
    strcpy(options[3].default_value,"100");
    strcpy(options[3].value,options[0].default_value);
    strcpy(options[3].question,"Koks maksimalus klientu skaicius?\n");

    strcpy(options[4].value,"<sources>");
    strcpy(options[4].default_value,"2");
    strcpy(options[4].value,options[0].default_value);
    strcpy(options[4].question,"Koks maksimalus saltiniu skaicius?\n");

    strcpy(options[5].value,"<queue-size>>");
    strcpy(options[5].default_value,"524288");
    strcpy(options[5].value,options[0].default_value);
    strcpy(options[5].question,"Koks transliacinio buferio dydis, B?\n");

    strcpy(options[6].value,"<source-password>");
    strcpy(options[6].default_value,"hackme");
    strcpy(options[6].value,options[0].default_value);
    strcpy(options[6].question,"Koks saltinio slaptazodis?\n");

    strcpy(options[7].value,"<relay-password>");
    strcpy(options[7].default_value,"hackme");
    strcpy(options[7].value,options[0].default_value);
    strcpy(options[7].question,"Koks reles slaptazodis?\n");

    strcpy(options[8].value,"<admin-user>");
    strcpy(options[8].default_value,"admin");
    strcpy(options[8].value,options[0].default_value);
    strcpy(options[8].question,"Koks administratoriaus prisijungimo vardas?\n");

    strcpy(options[9].value,"<admin-password>");
    strcpy(options[9].default_value,"hackme");
    strcpy(options[9].value,options[0].default_value);
    strcpy(options[9].question,"Koks administratoriaus slaptazodis?\n");

    strcpy(options[10].value,"<port>");
    strcpy(options[10].default_value,"8000");
    strcpy(options[10].value,options[0].default_value);
    strcpy(options[10].question,"Koks saltinio klausymosi prievado numeris?\n");

    strcpy(options[11].value,"<!-- Normal mounts -->");
    strcpy(options[11].default_value,"<!-- Normal mounts -->");
    strcpy(options[11].value,options[0].default_value);
    strcpy(options[11].question,"Ar norite prideti saltni?\n");

    strcpy(options[12].value,"<mount-name>");
    strcpy(options[12].default_value,"Earth");
    strcpy(options[12].value,options[0].default_value);
    strcpy(options[12].question,"Kur yra sis serveris?\n");

    strcpy(options[13].value,"<username>");
    strcpy(options[13].default_value,"Earth");
    strcpy(options[13].value,options[0].default_value);
    strcpy(options[13].question,"Kur yra sis serveris?\n");

    strcpy(options[14].value,"<password>");
    strcpy(options[14].default_value,"Earth");
    strcpy(options[14].value,options[0].default_value);
    strcpy(options[14].question,"Kur yra sis serveris?\n");

    strcpy(options[15].value,"<max-listeners>");
    strcpy(options[15].default_value,"Earth");
    strcpy(options[15].value,options[0].default_value);
    strcpy(options[15].question,"Kur yra sis serveris?\n");

    strcpy(options[16].value,"<max-listener-duration>");
    strcpy(options[16].default_value,"Earth");
    strcpy(options[16].value,options[0].default_value);
    strcpy(options[16].question,"Kur yra sis serveris?\n");

    strcpy(options[17].value,"<location>");
    strcpy(options[17].default_value,"Earth");
    strcpy(options[17].value,options[0].default_value);
    strcpy(options[17].question,"Kur yra sis serveris?\n");

    strcpy(options[18].value,"<location>");
    strcpy(options[18].default_value,"Earth");
    strcpy(options[18].value,options[0].default_value);
    strcpy(options[18].question,"Kur yra sis serveris?\n");

    strcpy(options[19].value,"<location>");
    strcpy(options[19].default_value,"Earth");
    strcpy(options[19].value,options[0].default_value);
    strcpy(options[19].question,"Kur yra sis serveris?\n");

    strcpy(options[20].value,"<location>");
    strcpy(options[20].default_value,"Earth");
    strcpy(options[20].value,options[0].default_value);
    strcpy(options[20].question,"Kur yra sis serveris?\n");

    strcpy(options[21].value,"<location>");
    strcpy(options[21].default_value,"Earth");
    strcpy(options[21].value,options[0].default_value);
    strcpy(options[21].question,"Kur yra sis serveris?\n");

    strcpy(options[22].value,"<location>");
    strcpy(options[22].default_value,"Earth");
    strcpy(options[22].value,options[0].default_value);
    strcpy(options[22].question,"Kur yra sis serveris?\n");

    strcpy(options[23].value,"<location>");
    strcpy(options[23].default_value,"Earth");
    strcpy(options[23].value,options[0].default_value);
    strcpy(options[23].question,"Kur yra sis serveris?\n");

}

int prideti_dar_saltiniu = '1';

int main()
{
    FILE * inFile;
    FILE * outFile;
    FILE * newFile;
    char mystring [100];
    int i = 0;
    int j = 0;

    inFile = fopen("test.txt" , "r");
    outFile = fopen("output.xml", "w+");

    char inString[100];

    //  init_options();

    char str[100];

    int k = 1;
    newFile = fopen("newfile.xml", "w+");
    if (inFile == NULL) perror ("Klaida atidarant byla!");
    else
    {
        fprintf(newFile, "<icecast>\n");
        printf(" Serverio vietove? ");
        gets(inString);
        fprintf(newFile, "    <location>%s</location>\n",inString);
        printf(" Serverio administratriaus el. pasto adresas? ");
        gets(inString);
        fprintf(newFile, "    <admin>%s</admin>\n",inString);
        printf(" Kompiuterio pavadinimas? ");
        gets(inString);
        fprintf(newFile, "    <hostname>%s</hostname>\n",inString);
        fprintf(newFile, "    <limits>\n");
        printf(" Didziausias klientu skaicius? ");
        gets(inString);
        fprintf(newFile, "        <clients>%s</clients>\n",inString);
        printf(" Didziausias saltiniu skaicius ");
        gets(inString);
        fprintf(newFile, "        <sources>%s</sources>\n",inString);
        fprintf(newFile, "        <queue-size>524288</queue-size>\n");
        fprintf(newFile, "        <client-timeout>30</client-timeout>\n");
        fprintf(newFile, "        <header-timeout>15</header-timeout>\n");
        fprintf(newFile, "        <source-timeout>10</source-timeout>\n");
        fprintf(newFile, "        <burst-on-connect>1</burst-on-connect>\n");
        fprintf(newFile, "        <burst-size>65535</burst-size>\n");
        fprintf(newFile, "    </limits>\n");
        fprintf(newFile, "    <authentication>\n");
        printf(" Saltiniu slaptazodis ");
        gets(inString);
        fprintf(newFile, "        <source-password>%s</source-password>\n",inString);
        printf(" Reliu slaptazodis ");
        gets(inString);
        fprintf(newFile, "        <relay-password>%s</relay-password>\n",inString);
        printf(" Administratoriaus vartotojo vardas ");
        gets(inString);
        fprintf(newFile, "        <admin-user>%s</admin-user>\n",inString);
        printf(" Administratoriaus slaptazodis ");
        gets(inString);
        fprintf(newFile, "        <admin-password>%s</admin-password>\n",inString);
        fprintf(newFile, "    </authentication>\n");
        fprintf(newFile, "    <directory>\n");
        fprintf(newFile, "        <yp-url-timeout>15</yp-url-timeout>\n");
        fprintf(newFile, "        <yp-url>http://dir.xiph.org/cgi-bin/yp-cgi</yp-url>\n");
        fprintf(newFile, "    </directory>\n");
        fprintf(newFile, "    <listen-socket>\n");
        printf(" Saltiniu klausymosi portas ");
        gets(inString);
        fprintf(newFile, "        <port>%s</port>\n",inString);
        fprintf(newFile, "    </listen-socket>\n");
        fprintf(newFile, "    <http-headers>\n");
        fprintf(newFile, "        <header name=\"Access-Control-Allow-Origin\" value=\"*\" />\n");
        fprintf(newFile, "    </http-headers>\n");

        while(k==1)
        {
            printf(" Saltinio pavadinimas ");
            gets(inString);
            fprintf(newFile, "    <mount type=\"normal\">\n");
            fprintf(newFile, "        <mount-name>/%s</mount-name>\n",inString);
            printf(" Saltinio vartotojo vardas ");
            gets(inString);
            fprintf(newFile, "       <username>%s</username>\n",inString);
            printf(" Saltinio vartotojo slaptazodis ");
            gets(inString);
            fprintf(newFile, "        <password>%s</password>\n",inString);
            printf(" Saltinio didziausias klausytoju skaicius ");
            gets(inString);
            fprintf(newFile, "        <max-listeners>1</max-listeners>\n");
            fprintf(newFile, "    </mount>\n");
            printf(" PRIDETI DAR SALTINIU? 1 - taip, 0 - ne ");
            gets(inString);

            if(strcmp(inString,"1")!=0)
            {
                k = 0;
            }
        }

        fprintf(newFile, "    <fileserve>1</fileserve>\n");
        fprintf(newFile, "    <paths>\n");
        fprintf(newFile, "        <logdir>./log</logdir>\n");
        fprintf(newFile, "        <webroot>./web</webroot>\n");
        fprintf(newFile, "        <adminroot>./admin</adminroot>\n");
        fprintf(newFile, "        <alias source=\"/\" destination=\"/status.xsl\"/>\n");
        fprintf(newFile, "    </paths>\n");
        fprintf(newFile, "    <logging>\n");
        fprintf(newFile, "        <accesslog>access.log</accesslog>\n");
        fprintf(newFile, "        <errorlog>error.log</errorlog>\n");
        fprintf(newFile, "        <loglevel>3</loglevel>\n");
        fprintf(newFile, "        <logsize>10000</logsize> \n");
        fprintf(newFile, "    </logging>\n");
        fprintf(newFile, "</icecast>\n");

        fclose(newFile);
    }

    printf("Aciu! Iki :)");

    return 0;
}
