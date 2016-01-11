#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE * inFile;
    FILE * outFile;
    FILE * newFile;
    char mystring [100];
    int i = 0;
    int j = 0;
    int k = 1;

    char inString[100];

    inFile = fopen("test.txt" , "r");

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
