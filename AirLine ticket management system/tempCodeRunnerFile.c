{
            printf("<< You want to check your ticket approval >>\n\n");
            printf("\n");

            countInfo = 0;
            readPassInfo = fopen("CheckPassStatus.txt","r");

            for(i=0; fgets(words,sizeof(words),readPassInfo) != NULL; i++)
            {
                strcpy(InfoList[i],words);
                countInfo++;
            }
            fclose(readPassInfo);
            PassInfoEntry(InfoList,countInfo);

            printf("-------------------------------\n");
            for(i=0;i<(countInfo/7);i++)
            {
                    printf("* Name          -> %s",p[i].Name);
                    printf("* Departure     -> %s",p[i].From);
                    printf("* Destination   -> %s",p[i].To);
                    printf("* Booking Date  -> %s",p[i].BookingDate);
                    printf("* Class         -> %s",p[i].Class);
                    printf("* Current Status-> %s",p[i].status);
                    printf("\n");
            }
            printf("-------------------------------\n\n");

            printf("<< Press y to continue  >>\n");
            scanf("%c",&cont);
        }