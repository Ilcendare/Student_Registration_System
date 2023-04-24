/***************************************************/
/*  Author      : Mahmoud Sayed                     *
 *  Date        : 23 April 2023                     *
 *  Description : Student registration program.     *
 *  Email       : Thrtr619@gmail.com                *
 *                                                  *
 ***************************************************/


#include "Student_Registration.h"


int main() {
    Student_Registration_init();
    Student_Registration_loadData();
    Student_Registration_menu();
    Student_Registration_saveData();
    return 0;
}
