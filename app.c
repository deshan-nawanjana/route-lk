/*

    RouteLK
    Developed by W. M. Deshan Nawanjana

*/

#include <stdio.h>

// Database Creation
char s[52][16] = {
                    "Fort","Kompannaweediya","Kollupitiya",
                    "Havelock Town","Wellawatte","Dehiwala",
                    "Mount Lavinia","Soysapura","Katubedda",
                    "Rawathawatta","Moratuwa","Walana",
                    "Panadura","Wadduwa","Pothupitiya",
                    "Kaluthara","Katukurunda","Maggona",
                    "Beruwala","Moragalla","Aluthgama",
                    "Bentota","Induruwa","Kosgoda",
                    "Ahungalla","Wathuregama","Wellabada",
                    "Balapitiya","Wellawatta","Randombe",
                    "Ambalangoda","Urawatte","Madampagama",
                    "Akuralla","Kahawa","Godagama",
                    "Thelwatta","Peraliya","Seenigama",
                    "Wewala","Thiranagama","Pathuwatta",
                    "Kumarakanda","Dodanduwa","Rajgama",
                    "Gamaddegoda","Mihira","Owakanda",
                    "Boossa","Gintota","Mahamodara","Galle"
};
int  r[16][16]   = {
                    {1,2,3,4,5,6,7,8,9,10,32,33},
                    {47,42,43,36,8,9,10,32,33},
                    {1,2,18,17,16,27,26,25,9,10,32,33},
                    {1,2,18,17,16,15,14,13,12,11,10,32,33},
                    {1,2,3,4,38,37,36,35,29,30,31},
                    {21,20,22,16,52,5,4,38,37,36,29,30,31},
                    {1,2,18,17,16,15,14,13,12,11,10,28,29,30,31},
                    {19,20,22,16,15,23,24,11,10,32,33},
                    {1,2,18,17,16,15,14,13,12,11,10,28,29,34},
                    {1,2,3,4,38,37,36,35,29,30,31},
                    {13,14,15,16,52,51,50,3,39,40,48},
                    {1,2,3,39,40,41,42,43,44,45},
                    {49,48,40,41,42,43,44,46},
                    {33,32,10,9,8,36,43,42,47},
                    {49,40,39,3,50,51,52,16,15,14,22,20,21},
                    {21,20,22,16,52,5,4,38,37,36,43,42,47}
};

char u_fn[] = "John";
char u_ln[] = "Wick";
int  u_lc   = 0;

// Universal Variables (a,b) for Location ID and Destination ID
int a,b;

// Function: Print Stop Name by ID
void print_s(int n) {
    for(int i=0;i<16;i++) {
      int x;
      x = s[n][i];
      if(x!=0) {printf("%c", s[n][i]);}
    }
}
void print_s_2(int n) {
    for(int i=0;i<16;i++) {
      printf("%c", s[n][i]);
    }
}

// Function: Print All of Stops As a List
void print_stop_list() {
    printf("    ");
    for(int i=1;i<53;++i) {

        char n[2];
        int k = i;
        itoa(k,n,10);
        if(strlen(n)==1) {printf("[0%s] ", n);}
        else {printf("[%s] ", n);}

        print_s_2(i-1);
        if(i%5==0) {printf("\n    ");}
    }
    printf("\n\n");
}


// Function: Print Route Info
void print_bus_info(int n) {

    char g[2];
    int k = n+1;
    itoa(k,g,10);
    if(strlen(g)==1) {printf("       0%s [ ", g);}
    else {printf("       %s [ ", g);}

    print_s(r[n][0]-1);
    printf(" > ");
    for(int i=0;i<16;++i) {
        if(r[n][i]==0) {print_s(r[n][i-1]-1);i=17;}
    }
    printf(" ]");
}
void print_bus_info_2(int n) {

    char g[2];
    int k = n+1;
    itoa(k,g,10);
    if(strlen(g)==1) {printf("0%s", g);}
    else {printf("%s", g);}

}
void print_bus_info_3(int n) {

    char g[2];
    int k = n+1;
    itoa(k,g,10);
    if(strlen(g)==1) {printf("0%s  ", g);}
    else {printf("%s  ", g);}

    print_s_2(r[n][0]-1);
    printf(" > ");
    for(int i=0;i<16;++i) {
        if(r[n][i]==0) {print_s_2(r[n][i-1]-1);i=17;}
    }
}


// Function: Clear Console Window
void clear() {system("cls");}

// Function: Main
void main() {
    system("TITLE RouteLK - Bus Route Finding Tool"); // Set Console Title
  //  system("mode con: cols=120 lines=38"); // Set Console Window Size
    welcome(); // Jump to Welcome
}

// Function: Welcome Screen
void welcome() {
    clear();
    printf("  +===========================================+\n");
    printf("  |    ____             _       _     _  __   |\n");
    printf("  |   |  _ \\ ___  _   _| |_ ___| |   | |/ /   |\n");
    printf("  |   | |_) / _ \\| | | | __/ _ \\ |   | \' /    |\n");
    printf("  |   |  _ < (_) | |_| | ||  __/ |___| . \\    |\n");
    printf("  |   |_| \\_\\___/ \\__,_|\\__\\___|_____|_|\\_\\   |\n");
    printf("  |                                           |\n");
    printf("  |     Fulfill Your Transportation Needs     |\n");
    printf("  |                                           |\n");
    printf("  +===========================================+\n");
    printf("  |                                           |\n");
    printf("  |    Location > Destination > Your Route    |\n");
    printf("  |                                           |\n");
    printf("  |                It's Easy!                 |\n");
    printf("  |                                           |\n");
    printf("  +===========================================+\n");
    printf("  |                                           |\n");
    printf("  |               Developed By:               |\n");
    printf("  |                                           |\n");
    printf("  |           W. M. Deshan Nawanjana          |\n");
    printf("  |                                           |\n");
    printf("  +===========================================+\n\n");
    printf("  Press Enter to Continue > ");

    char enter = 0;
    while (enter != '\r' && enter != '\n') { enter = getchar(); }
    home();
}

// Function: Home
void home() {
    clear();

    printf("  +===========================================+\n");
    printf("  |    ____             _       _     _  __   |\n");
    printf("  |   |  _ \\ ___  _   _| |_ ___| |   | |/ /   |\n");
    printf("  |   | |_) / _ \\| | | | __/ _ \\ |   | \' /    |\n");
    printf("  |   |  _ < (_) | |_| | ||  __/ |___| . \\    |\n");
    printf("  |   |_| \\_\\___/ \\__,_|\\__\\___|_____|_|\\_\\   |\n");
    printf("  |                                           |\n");
    printf("  |     Fulfill Your Transportation Needs     |\n");
    printf("  |                                           |\n");
    printf("  +===========================================+\n\n");

    printf("    User : %s %s (",u_fn,u_ln); print_s(u_lc);printf(")\n\n");

    printf("  +===========================================+\n");
    printf("  |                                           |\n");
    printf("  |               - MAIN MENU -               |\n");
    printf("  |                                           |\n");
    printf("  |   [1] Navigate                            |\n");
    printf("  |   [2] Explore                             |\n");
    printf("  |   [3] Settings                            |\n");
    printf("  |   [4] Instructions                        |\n");
    printf("  |   [5] About                               |\n");
    printf("  |   [6] Exit                                |\n");
    printf("  |                                           |\n");
    printf("  +===========================================+\n\n");
    printf("   Select a Menu Item > ");

    char x;
    scanf("%c",&x);

    if((int)x==49) {navigate();}
    else if((int)x==50) {explore();}
    else if((int)x==51) {settings();}
    else if((int)x==52) {instructions();}
    else if((int)x==53) {about();}
    else if((int)x==54) {clear();}
    else {home();}

}

/***************************************************************/
/*  1. NAVIGATE                                                */
/***************************************************************/

void navigate() {
    clear();
    printf("\n");
    printf("   Select Your Current Location :\n\n");

    printf("      [1] Home ("); print_s(u_lc); printf(")\n");
    printf("      [2] Select Other...\n");
    printf("      [3] Back to Home\n\n");

    printf("   Select Item > ");

    char x;
    scanf("%c",&x);

    if((int)x==49) {a = u_lc;set_des();}
    else if((int)x==50) {set_loc();}
    else if((int)x==51) {home();}
    else {navigate();}
}

// SET LOC, DES
void set_loc() {
    clear();
    printf("\n");
    print_stop_list();

    printf("    Select Location    > ");

    int x;
    scanf("%d",&x);

    if(x>0 && x<53) {a = x - 1; set_des();}
    else {set_loc();}
}
void set_des() {
    clear();
    printf("\n");
    print_stop_list();

    printf("    Select Location    > "); print_s(a); printf("\n");
    printf("    Select Destination > ");

    int x;
    scanf("%d",&x);

    if(x>0 && x<53 && (x-1)!=a) {b = x - 1; get_result();}
    else {set_des();}
}

// GET RESULT
void get_result() {
    clear();
    printf("  +===========================================+\n");
    printf("  |                                           |\n");
    printf("  |   Location    > "); print_s_2(a); printf("          |\n");
    printf("  |   Destination > "); print_s_2(b); printf("          |\n");
    printf("  |                                           |\n");
    printf("  +===========================================+\n\n");

    printf("    Results :\n\n");

    int i, j;
    int c = 0;

    // Find single routes for the transportation
    for(i=0;i<16;i++) {
        int x = 0, y = 0;
        for(j=0;j<15;j++) {
            if(r[i][j]==a+1) {x = 1;}
            if(r[i][j]==b+1) {y = 1;}
        }
        if(x==1 && y==1) {
                c+=1;
        printf("  +-------------------------------------------+\n");
                print_bus_info(i);
                printf("\n");}
    }

    if(c==0) {
        // Find switchable routes for the transportation
        int m[16] = {};
        int n[16] = {};
        int d = 0;

        // Select Routes that available Current Location
        for(i=0;i<16;i++) {
            for(j=0;j<15;j++) {
                if(r[i][j]==a+1) {
                        m[d] = i;d += 1;
                }
            }
        }

        // Select Routes that available Destination
        d = 0;
        for(i=0;i<16;i++) {
            for(j=0;j<15;j++) {
                if(r[i][j]==b+1) {
                        n[d] = i;d += 1;
                }
            }
        }

        // Find for common stops
        d = 0;
        int o[16][3] = {};
        for(i=0;i<16;i++) {
            for(j=0;j<16;j++) {
                if(m[i]!=0 && n[j]!=0 && m[i]!=n[j]) {
                    int r1 = m[i];
                    int r2 = n[j];
                    int cm = getCommon(r1,r2);
                    if(cm!=0) {
                        o[d][0] = r1; // Route 1 ID
                        o[d][1] = cm; // Switch Point
                        o[d][2] = r2; // Route 2 ID
                        d +=1;
                    }
                }
            }
        }

        if(d!=0) {
            for(i=0;i<16;i++) {
                int r1 = o[i][0];
                int sw = o[i][1]-1;
                int r2 = o[i][2];
                if(sw>-1) {
                    printf("  +-------------------------------------------+\n");
                    print_bus_info(r1);
                    printf("\n       >> Switch @ ");
                    print_s(sw);
                    printf("\n");
                    print_bus_info(r2);
                    printf("\n");
                }
            }
                printf("  +-------------------------------------------+\n");
        }
    }
    else {
        printf("  +-------------------------------------------+\n");
    }

    printf("\n");
    printf("  +===========================================+\n");
    printf("  |                                           |\n");
    printf("  |      1. Search Again                      |\n");
    printf("  |      2. Back to Home                      |\n");
    printf("  |                                           |\n");
    printf("  +===========================================+\n\n");
    printf("  Select an Option > ");

    char x;
    scanf("%c",&x);

    if((int)x==49) {navigate();}
    else if((int)x==50) {home();}
    else {get_result();}

}

// GET COMMON STOPS
int getCommon(int r1, int r2) {
    int c = 0;
    for(int i=0;i<16;i++) {
        for(int j=0;j<16;j++) {
            int r1s = r[r1][i];
            int r2s = r[r2][j];
            if(r1s==r2s && r1s!=0) {c = r[r1][i];}
        }
    }

   // printf("CHK BUS: %d - %d = %d\n",r1+1,r2+1,c);

    return c;
}


/***************************************************************/
/*  2. EXPLORE                                                 */
/***************************************************************/

void explore() {
    clear();
    printf("  +===========================================+\n");
    printf("  |                                           |\n");
    printf("  |    Explore Menu                           |\n");
    printf("  |                                           |\n");
    printf("  +-------------------------------------------+\n");
    printf("  |                                           |\n");
    printf("  |    [1] Routes                             |\n");
    printf("  |    [2] Locations                          |\n");
    printf("  |    [3] Database Info                      |\n");
    printf("  |    [4] Back to Home                       |\n");
    printf("  |                                           |\n");
    printf("  +===========================================+\n\n");

    printf("   Select Item > ");

    char x;
    scanf("%c",&x);

    if((int)x==49) {routes();}
    else if((int)x==50) {locations();}
    else if((int)x==51) {dbsinfo();}
    else if((int)x==52) {home();}
    else {explore();}
}

// ROUTES
void routes() {
    clear();
    printf("\n\n");
    for(int i=0;i<16;++i) {
        print_bus_info(i);
        printf("\n");
    }

    printf("\n");
    printf("       Enter Route Name > ");
    int x;
    scanf("%d",&x);
    if(x>0 && x<17) {show_route(x-1);}
    else {routes();}
}
void show_route(int x) {
    clear();

    printf("  +===========================================+\n");
    printf("  | Route No. ");
    print_bus_info_2(x);printf("                              |\n");
    printf("  +-------------------------------------------+\n");
    for(int i=0;i<15;i++) {
        int sid = r[x][i];
        if(sid!=0) {
            printf("  | ");
            print_s_2(sid-1);
            printf("                          |\n");
        }
    }
    printf("  +-------------------------------------------+\n");
    printf("  |   1. Back to Routes                       |\n");
    printf("  |   2. Back to Explore Menu                 |\n");
    printf("  |   3. Back to Home                         |\n");
    printf("  +===========================================+\n\n");
    printf("  Select an Option > ");

    char k;
    scanf("%c",&k);

    if((int)k==49) {routes();}
    else if((int)k==50) {explore();}
    else if((int)k==51) {home();}
    else {show_route(x);}
}

// LOCATION
void locations() {
    clear();
    printf("\n");
    print_stop_list();

    printf("    Select Location to View Routes > ");

    int x;
    scanf("%d",&x);

    if(x>0 && x<53) {a = x - 1; show_locations(x-1);}
    else {locations();}
}
void show_locations(int x) {
    clear();

    printf("  +===========================================+\n");
    printf("  | Routes on : ");
    print_s_2(x);printf("              |\n");
    printf("  +-------------------------------------------+\n");


    for(int i=0;i<16;i++) {
        for(int j=0;j<16;j++) {
            if(r[i][j]==x+1) {
                printf("  | ");
                print_bus_info_3(i);
                printf("   |\n");
            }
        }
    }
    printf("  +-------------------------------------------+\n");
    printf("  |   1. Back to Locations                    |\n");
    printf("  |   2. Back to Explore Menu                 |\n");
    printf("  |   3. Back to Home                         |\n");
    printf("  +===========================================+\n\n");
    printf("  Select an Option > ");

    char k;
    scanf("%c",&k);

    if((int)k==49) {locations();}
    else if((int)k==50) {explore();}
    else if((int)k==51) {home();}
    else {show_locations(x);}
}

// DBS-INFO
void dbsinfo() {
    clear();

    int c_r = sizeof(r)/64;
    int c_l = sizeof(s)/16;

    printf("  +===========================================+\n");
    printf("  | Database Infromation                      |\n");
    printf("  +-------------------------------------------+\n");
    printf("  |   Routes Count    : %d                    |\n",c_r);
    printf("  |   Locations Count : %d                    |\n",c_l);
    printf("  +-------------------------------------------+\n");
    printf("  |   1. Back to Explore Menu                 |\n");
    printf("  |   2. Back to Home                         |\n");
    printf("  +===========================================+\n\n");
    printf("  Select an Option > ");

    char k;
    scanf("%c",&k);

    if((int)k==49) {explore();}
    else if((int)k==50) {home();}
    else {dbsinfo();}
}


/***************************************************************/
/*  3. SETTINGS                                                */
/***************************************************************/

void settings() {
    clear();
    printf("  +===========================================+\n");
    printf("  |                                           |\n");
    printf("  |    Settings                               |\n");
    printf("  |                                           |\n");
    printf("  +-------------------------------------------+\n");
    printf("  |                                           |\n");
    printf("  |    [1] View User Info                     |\n");
    printf("  |    [2] Edit Personal Data                 |\n");
    printf("  |    [3] Set Hometown                       |\n");
    printf("  |    [4] Back to Home                       |\n");
    printf("  |                                           |\n");
    printf("  +===========================================+\n\n");

    printf("   Select Item > ");

    char x;
    scanf("%c",&x);

    if((int)x==49) {view_ui();}
    else if((int)x==50) {edit_ui();}
    else if((int)x==51) {set_ulc();}
    else if((int)x==52) {home();}
    else {settings();}
}


// VIEW USER INFO
void view_ui() {
    clear();
    printf("  +===========================================+\n");
    printf("  | User Info                                 |\n");
    printf("  +===========================================+\n\n");

    printf("     First Name : %s\n",u_fn);
    printf("     Last Name  : %s\n",u_ln);
    printf("     Hometown   : "); print_s(u_lc);printf("\n\n");

    printf("  +===========================================+\n");
    printf("  |   1. Back to Settings                     |\n");
    printf("  |   2. Back to Home                         |\n");
    printf("  +===========================================+\n\n");
    printf("  Select an Option > ");

    char k;
    scanf("%c",&k);

    if((int)k==49) {settings();}
    else if((int)k==50) {home();}
    else {view_ui();}
}

// EDIT USER INFO
void edit_ui() {
    clear();
    printf("\n");
    printf("  Enter First Name > ");
    scanf("%s",&u_fn);
    printf("  Enter Last Name  > ");
    scanf("%s",&u_ln);
    settings();
}

// SET HOMETOWN
void set_ulc() {
    clear();
    printf("\n");
    print_stop_list();

    printf("    Select Location to Make your Hometown > ");

    int x;
    scanf("%d",&x);

    if(x>0 && x<53) {u_lc = x - 1;settings();}
    else {set_ulc();}
}


/***************************************************************/
/*  4. INSTRCUTIONS                                                */
/***************************************************************/


void instructions() {
    clear();
    printf("\n");
    printf("  - Instructions -  \n\n");
    printf("    > RouteLK is a Bus Route finding tool for your transportation needs.\n");
    printf("\n");
    printf("    > In the Main Menu, Select \'Navigate\' to do start the fetching process.\n");
    printf("    > Then you can enter your location and destination by specific id that belongs to those cities.\n");
    printf("    > The you will able to see the bus routes that you can reach to your destination.\n");
    printf("    > Sometimes you may need to switch one route from another.\n");
    printf("    > RouteLK will show you those switch options also.\n");
    printf("\n");
    printf("    > In the Explore Menu, There are some more features.\n");
    printf("    > You can check the all routes with their stops.\n");
    printf("    > Also you can select a city and check the routes that cross through that city.\n");
    printf("    > And you may see the database information here.\n");
    printf("\n");
    printf("    > In the Settings, You can update some information belongs to you.\n");
    printf("    > Options to edit your user name and hometown is available in Settings.\n");
    printf("    > By setting your hometown, you may able to do the navigation search easily.\n\n\n");

    printf("  Type 1 and Enter to go Back to Home > ");

    char k;
    scanf("%c",&k);
    if((int)k==49) {home();}
    else {instructions();}
}


/***************************************************************/
/*  4. ABOUT                                                */
/***************************************************************/

// VIEW ABOUT
void about() {
    clear();

    printf("  +===========================================+\n");
    printf("  |    ____             _       _     _  __   |\n");
    printf("  |   |  _ \\ ___  _   _| |_ ___| |   | |/ /   |\n");
    printf("  |   | |_) / _ \\| | | | __/ _ \\ |   | \' /    |\n");
    printf("  |   |  _ < (_) | |_| | ||  __/ |___| . \\    |\n");
    printf("  |   |_| \\_\\___/ \\__,_|\\__\\___|_____|_|\\_\\   |\n");
    printf("  |                                           |\n");
    printf("  |            About The Developer            |\n");
    printf("  |                                           |\n");
    printf("  +===========================================+\n");
    printf("  |                                           |\n");
    printf("  |                                           |\n");
    printf("  |            W. M. Deshan Nawanjana         |\n");
    printf("  |            deshan.jvc@gmail.com           |\n");
    printf("  |            http://dnjs.info/              |\n");
    printf("  |            http://dn-w.blogspot.com/      |\n");
    printf("  |                                           |\n");
    printf("  |                                           |\n");
    printf("  +-------------------------------------------+\n");
    printf("  |   1. Back to Home                         |\n");
    printf("  +===========================================+\n\n");
    printf("  Select an Option > ");

    char k;
    scanf("%c",&k);
    if((int)k==49) {home();}
    else {about();}


}




