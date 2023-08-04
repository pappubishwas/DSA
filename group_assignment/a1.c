#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct student
{
    int roll, branchId;
    float cgpa;
    char name[30];
    struct student *snext;
};
struct university
{
    int universityId, yearStart;
    char universityName[30], universityLocation[30];
    struct university *unext;
};
struct branchDetails;
struct branch
{
    int universityId;
    struct branch *bnext;
    struct branchDetails *bd;
};
struct branchDetails
{
    int branchId;
    char branchName[30];
    struct branchDetails *bdnext;
};

struct head_node
{
    struct student *snext;
    struct student *slnext;
    struct university *unext;
    struct branch *bnext;
} *start = NULL;

struct asending
{
    int yearS;
    struct asending *next;
    struct university *aduni;
} *root = NULL;

void studentInfo();
void universityInfo();
void branchInfo();
void display();
int checkRoll(int);
int checkUniId(int);
int checkBranch(int, int);
int checkBranchStudent(int);
void display_kiit();
void display_kiitCse();
void display_branch(char *);
void display_ascending();
void deleteStudent(int roll);
void deleteUniversity();
void deleteBranch();
int checkSubstring(char *str, char *search);
void displayStudentBySubtring();
void displayUniversityBySubtring();
void update();
int main()
{
    int c, n = 1;

    while (n == 1)
    {
        printf("1.Add  student information.\n2.Add University information.\n3.Add branch details.\n4.Display three database.\n5.Display Kiit student details.\n6.Display kiit student details with cse branch.\n7.Display the list of Branches available in  given University.\n8.Display the University details in ascending order of their year of starting.\n9.Delete using key value.\n10.Display the all Student name/ all University name for a given name substring.\n11.Exit\n");
        printf("Enter the number which opertation you want: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
        {

            studentInfo();
            break;
        }
        case 2:
            universityInfo();
            break;
        case 3:
            branchInfo();
            break;
        case 4:
            display();
            break;
        case 5:
            display_kiit();
            break;
        case 6:
            display_kiitCse();
            break;
        case 7:
        {
            char uni[30];
            printf("Enter university name:");
            scanf("%s", &uni);
            fflush(stdin);
            display_branch(uni);
            break;
        }
        case 8:
            display_ascending();
            break;
        case 9:
        {
            int c1, n1 = 1;
            while (n1 == 1)
            {
                printf("1.Delete student details.\n2.Delete university details.\n3.Delete branch.\n4.Exit\n");
                printf("Enter the number which opertation you want: ");
                scanf("%d", &c1);
                switch (c1)
                {
                case 1:
                {
                    int roll;
                    printf("Enter the roll that student data you want to delete : ");
                    scanf("%d", &roll);
                    deleteStudent(roll);
                    break;
                }
                case 2:
                    deleteUniversity();
                    break;
                case 3:
                    deleteBranch();
                    break;

                default:
                    break;
                }
                printf("\nPress 1 to continune || 0 to exit(delete): ");
                scanf("%d", &n1);
            }
            break;
        }
        case 10:
        {
            displayStudentBySubtring();
            displayUniversityBySubtring();
            break;
        }
        case 11:
        {
            update();
            break;
        }
        default:
            exit(0);
        }
        printf("\nPress 1 to continune || 0 to exit: ");
        scanf("%d", &n);
        if (n == 0 || n != 1)
            exit(0);
    }
}

// For Taking student information.............

void studentInfo()
{
    char nam[30];
    float cg;
    int r, bi, n = 1, c = 0;

    if (start == NULL)
    {
        struct head_node *head;
        head = (struct head_node *)malloc(sizeof(struct head_node));
        head->bnext = NULL;
        head->snext = NULL;
        head->slnext = NULL;
        head->unext = NULL;
        start = head;
    }
    while (n == 1)
    {
        struct student *t, *p = (struct student *)malloc(sizeof(struct student));
        fflush(stdin);
        printf("Enter your name: ");
        gets(nam);
        printf("Enter your roll: ");
        scanf("%d", &r);
        printf("Enter your cgpa: ");
        scanf("%f", &cg);
        printf("Enter your branchId: ");
        scanf("%d", &bi);
        strupr(nam);
        p->snext = NULL;
        p->branchId = bi;
        p->cgpa = cg;
        p->roll = r;
        strcpy(p->name, nam);
        if (start->snext == NULL)
        {
            int count1 = checkBranchStudent(p->branchId);
            if (count1 == 2)
            {
                start->snext = p;
            }
            else
            {
                if (count1 == 1)
                    printf("The branch is not available .\n");
                else if (count1 == 3)
                    printf("The universityId is not available .\n");
            }
        }
        else
        {
            int count = checkRoll(p->roll);
            int count1 = checkBranchStudent(p->branchId);
            if (count == 1 && count1 == 2)
            {
                t = start->snext;
                while (t->snext != NULL)
                {
                    t = t->snext;
                }
                t->snext = p;
            }
            else
            {
                if (count1 == 1)
                    printf("The branch is not available .\n");
                else if (count1 == 3)
                    printf("The universityId is not available .\n");
                else
                    printf("You are not promoted for same roll no.\n");
            }
        }
        printf("Press 1 to continue give another info || 0 to exit: ");
        scanf("%d", &n);
    }
}

// for checking student roll is unique or not.................

int checkRoll(int r)
{
    struct student *t;
    t = start->snext;
    while (t != NULL)
    {
        if (t->roll == r)
        {
            return 2;
            break;
        }
        t = t->snext;
    }
    if (t == NULL)
        return 1;
}

// for taking input of university details...............

void universityInfo()
{
    char un[30], ul[30];
    int ys, ui, n = 1;

    if (start == NULL)
    {
        struct head_node *head;
        head = (struct head_node *)malloc(sizeof(struct head_node));
        head->bnext = NULL;
        head->snext = NULL;
        head->slnext = NULL;
        head->unext = NULL;
        start = head;
    }
    while (n == 1)
    {
        struct university *t, *p = (struct university *)malloc(sizeof(struct university));
        fflush(stdin);
        printf("Enter university name: ");
        gets(un);
        fflush(stdin);
        printf("Enter university location: ");
        gets(ul);
        printf("Enter your universityID: ");
        scanf("%d", &ui);
        printf("Enter university year of start: ");
        scanf("%d", &ys);
        strupr(un);
        strupr(ul);
        p->unext = NULL;
        p->universityId = ui;
        p->yearStart = ys;
        strcpy(p->universityName, un);
        strcpy(p->universityLocation, ul);
        if (start->unext == NULL)
        {
            start->unext = p;
        }
        else
        {
            int count = checkUniId(p->universityId);
            if (count == 1)
            {
                t = start->unext;
                while (t->unext != NULL)
                {
                    t = t->unext;
                }
                t->unext = p;
            }
            else
                printf("You are not promoted for same universityID.\n");
        }
        printf("Press 1 to continue give another info || 0 to exit: ");
        scanf("%d", &n);
    }
}

// for checking universityID is unique or not .......

int checkUniId(int r)
{
    struct university *t;
    t = start->unext;
    while (t != NULL)
    {
        if (t->universityId == r)
        {
            return 2;
            break;
        }
        t = t->unext;
    }
    if (t == NULL)
        return 1;
}

// for taking branch information or adding ..........

void branchInfo()
{
    char bn[30];
    int bi, ui, n = 1, c;

    if (start == NULL)
    {
        struct head_node *head;
        head = (struct head_node *)malloc(sizeof(struct head_node));
        head->bnext = NULL;
        head->snext = NULL;
        head->slnext = NULL;
        head->unext = NULL;
        start = head;
    }
    while (n == 1)
    {
        struct branch *t, *temp, *p = (struct branch *)malloc(sizeof(struct branch));
        fflush(stdin);
        printf("Enter branch name: ");
        gets(bn);
        printf("Enter universityID: ");
        scanf("%d", &ui);
        printf("Enter branchId: ");
        scanf("%d", &bi);
        strupr(bn);
        struct branchDetails *t1, *q = (struct branchDetails *)malloc(sizeof(struct branchDetails));
        p->bnext = NULL;
        p->bd = NULL;
        p->universityId = ui;
        q->branchId = bi;
        q->bdnext = NULL;
        strcpy(q->branchName, bn);
        if (start->bnext == NULL)
        {
            start->bnext = p;
            p->bd = q;
        }
        else
        {
            t = start->bnext;
            while (t != NULL)
            {
                if (t->universityId == ui)
                {
                    free(p);
                    if (t->bd == NULL)
                    {
                        c = checkBranchStudent(q->branchId);
                        if (c == 1)
                        {

                            t->bd = q;
                        }
                        else
                            printf("You are not promoted for same branch no.\n");
                    }
                    else
                    {
                        c = checkBranchStudent(q->branchId);
                        if (c == 1)
                        {
                            t1 = t->bd;
                            while (t1->bdnext != NULL)
                            {
                                t1 = t1->bdnext;
                            }
                            t1->bdnext = q;
                        }
                        else
                            printf("You are not promoted for same branch no.\n");
                    }
                    break;
                }
                temp = t;
                t = t->bnext;
            }
            if (t == NULL)
            {
                c = checkBranchStudent(q->branchId);
                if (c == 1)
                {
                    temp->bnext = p;
                    p->bd = q;
                }
                else
                    printf("You are not promoted for same branch no.\n");
            }
        }
        printf("Press 1 to continue give another info || 0 to exit: ");
        scanf("%d", &n);
    }
}

// check branch is not avilable or not....

int checkBranchStudent(int b)
{
    int c = 0;
    struct branch *t;
    struct branchDetails *p;

    t = start->bnext;
    while (t != NULL)
    {
        p = t->bd;
        while (p != NULL)
        {
            if (p->branchId == b)
            {
                int uni = checkUniId(t->universityId);
                c = 1;
                if (uni == 2)
                    return 2;
                else
                    return 3;
                break;
            }
            p = p->bdnext;
        }
        if (c == 1)
        {
            break;
        }

        t = t->bnext;
    }
    if (t == NULL)
        return 1;
}

// display three database............

void display()
{
    struct student *s = start->snext;
    struct university *u = start->unext;
    struct branch *b = start->bnext;
    struct branchDetails *bdtemp;
    if (s == NULL)
        printf("\nThe student  database is empty.\n");
    else
    {
        printf("\nThe student details of the database:\n");
        while (s != NULL)
        {
            printf("Name: %s\n", s->name);
            printf("Roll Number: %d\n", s->roll);
            printf("CGPA: %0.4f\n", s->cgpa);
            printf("BranchId: %d\n\n", s->branchId);
            s = s->snext;
        }
    }
    if (u == NULL)
        printf("\nThe university  database is empty.\n");
    else
    {
        printf("\nThe University details of the database:\n");
        while (u != NULL)
        {
            printf("University name: %s\n", u->universityName);
            printf("University Location: %s\n", u->universityLocation);
            printf("UniversityId: %d\n", u->universityId);
            printf("Year of start: %d\n\n", u->yearStart);
            u = u->unext;
        }
    }
    if (b == NULL)
        printf("\nThe branch  database is empty.\n");
    else
    {
        printf("\nThe Branch details of the database:\n");
        while (b != NULL)
        {
            bdtemp = b->bd;
            while (bdtemp != NULL)
            {
                printf("UniversityId: %d\n", b->universityId);
                printf("BranchId: %d\n", bdtemp->branchId);
                printf("Banch name: %s\n\n", bdtemp->branchName);
                bdtemp = bdtemp->bdnext;
            }
            b = b->bnext;
        }
    }
}

// display student details of kiit university.............

void display_kiit()
{
    int k = 0;
    struct university *u;
    u = start->unext;
    char p[] = "KIIT";
    while ((u != NULL) && (strcmp(u->universityName, p) != 0))
    {
        u = u->unext;
    }
    if (u == NULL)
        printf("KIIT university is not in database\n");
    else
    {
        struct branch *b = start->bnext;
        while (b != NULL && b->universityId != u->universityId)
        {
            b = b->bnext;
        }
        if (b == NULL)
            printf("There is no universityId in branch databaase.");
        else
        {
            struct branchDetails *bdt = b->bd;
            while (bdt != NULL)
            {
                struct student *s = start->snext;
                while (s != NULL)
                {
                    if (s->branchId == bdt->branchId)
                    {
                        k = 1;
                        printf("Name: %s\n", s->name);
                        printf("Roll Number: %d\n", s->roll);
                        printf("CGPA: %0.4f\n", s->cgpa);
                        printf("BranchId: %d\n\n", s->branchId);
                    }
                    s = s->snext;
                }
                bdt = bdt->bdnext;
            }
            if (k == 0)
                printf("There is no kiit student in student database.\n");
        }
    }
}

// display student information of kiit university with cse branch.......

void display_kiitCse()
{
    int k = 0;
    struct university *u;
    u = start->unext;
    char p[] = "KIIT";
    char q[] = "CSE";
    while (strcmp(u->universityName, p) != 0 && u != NULL)
    {
        u = u->unext;
    }
    if (u == NULL)
        printf("KIIT university is not in database\n");
    else
    {
        struct branch *b = start->bnext;
        while (b != NULL && b->universityId != u->universityId)
        {
            b = b->bnext;
        }
        if (b == NULL)
            printf("There is no universityId in branch databaase.");
        else
        {
            struct branchDetails *bdt = b->bd;
            while (bdt != NULL)
            {
                struct student *s = start->snext;
                if (strcmp(bdt->branchName, q) == 0)
                {
                    while (s != NULL)
                    {
                        if (s->branchId == bdt->branchId)
                        {
                            k = 1;
                            printf("Name: %s\n", s->name);
                            printf("Roll Number: %d\n", s->roll);
                            printf("CGPA: %0.4f\n", s->cgpa);
                            printf("BranchId: %d\n\n", s->branchId);
                        }
                        s = s->snext;
                    }
                }

                bdt = bdt->bdnext;
            }
            if (k == 0)
                printf("There is no kiit student at CSE branch in student database.\n");
        }
    }
}

// display university branch using given university name.......

void display_branch(char *uni)
{
    int k = 0;
    strupr(uni);
    struct university *u;
    u = start->unext;
    while (u != NULL && strcmp(u->universityName, uni) != 0)
    {
        u = u->unext;
    }
    if (u == NULL)
        printf("Given university is not in database\n");
    else
    {
        struct branch *b = start->bnext;
        while (b != NULL && b->universityId != u->universityId)
        {
            b = b->bnext;
        }
        if (b == NULL)
            printf("There is no universityId in branch databaase.");
        else
        {
            struct branchDetails *bdt = b->bd;
            while (bdt != NULL)
            {
                k = 1;
                printf("Branch name: %s\n", bdt->branchName);
                printf("BranchId: %d\n\n", bdt->branchId);

                bdt = bdt->bdnext;
            }
            if (k == 0)
                printf("There is no branch in this university.\n");
        }
    }
}

// display university details according to year of start in ascending order.......

void display_ascending()
{
    root = NULL;
    struct asending *temp, *p, *q = root, *t1;
    struct university *u = start->unext;
    while (u != NULL)
    {
        p = (struct asending *)malloc(sizeof(struct asending));
        p->aduni = u;
        p->next = NULL;
        p->yearS = u->yearStart;
        if (root == NULL)
            root = p;
        else
        {
            q = root;
            // t1=q;
            while (q != NULL)
            {

                if (q->yearS > p->yearS)
                {
                    if (q == root)
                    {
                        temp = root;
                        root = p;
                        p->next = temp;
                    }
                    else
                    {
                        t1->next = p;
                        p->next = q;
                    }
                    break;
                }
                t1 = q;
                q = q->next;
            }
            if (q == NULL)
            {
                t1->next = p;
            }
        }
        u = u->unext;
    }

    if (root == NULL)
    {
        printf("There is no university details in university database.\n");
    }
    else
    {
        struct asending *t = root;
        while (t != NULL)
        {
            printf("University name: %s\n", t->aduni->universityName);
            printf("University Location: %s\n", t->aduni->universityLocation);
            printf("UniversityId: %d\n", t->aduni->universityId);
            printf("Year of start: %d\n\n", t->aduni->yearStart);
            t = t->next;
        }
    }
}

// Delete student information by key value of student roll............

void deleteStudent(int roll)
{
    struct student *p = start->snext, *temp;
    if (p == NULL)
        printf("There is no student in the student database.\n");
    else if (p->roll == roll)
        start->snext = p->snext;
    else
    {
        while (p != NULL && p->roll != roll)
        {
            temp = p;
            p = p->snext;
        }
        if (p == NULL)
            printf("There is no student in this roll in the student database.\n");
        else
            temp->snext = p->snext;
    }
}

// delete university details according with given universityID..............

void deleteUniversity()
{
    int uid;
    struct university *p = start->unext, *temp;
    printf("Enter the universityID that  university details you want to delete : ");
    scanf("%d", &uid);
    if (p == NULL)
        printf("There is no university in the university database.\n");
    else if (p->universityId == uid)
        start->unext = p->unext;
    else
    {
        while (p != NULL && p->universityId != uid)
        {
            temp = p;
            p = p->unext;
        }
        if (p == NULL)
            printf("There is no university in this universityID in the university database.\n");
        else
            temp->unext = p->unext;
    }
}

// Delete branch according with given branchID....................

void deleteBranch()
{
    int bid, k = 0;
    struct branch *p = start->bnext, *temp;
    printf("Enter the branchID that  branch you want to delete : ");
    scanf("%d", &bid);
    if (p == NULL)
        printf("There is no branch in the branch database.\n");
    else
    {
        while (p != NULL)
        {
            struct branchDetails *b = p->bd, *t;
            if (b->branchId == bid)
            {
                p->bd = b->bdnext;
                k = 1;
            }
            else
            {
                while (b != NULL && b->branchId != bid)
                {
                    t = b;
                    b = b->bdnext;
                }
                if (b != NULL)
                {
                    k = 1;
                    t->bdnext = b->bdnext;
                }
            }
            if (k == 1)
                break;
            p = p->bnext;
        }
        if (p == NULL)
            printf("There is no branch in this branchID in the branch database.\n");
    }
}

// display student name by uning substring of student name..................

void displayStudentBySubtring()
{
    char nam[20];
    fflush(stdin);
    printf("\nEnter student name substring : ");
    gets(nam);
    strupr(nam);
    struct student *s = start->snext;
    while (s != NULL)
    {
        int c = checkSubstring(s->name, nam);
        if (c == 1)
            printf("\nName:%s", s->name);

        s = s->snext;
    }
}

// display university  name by using substring of university name..........

void displayUniversityBySubtring()
{
    char nam[20];
    fflush(stdin);
    printf("\nEnter university name substring : ");
    gets(nam);
    strupr(nam);
    struct university *s = start->unext;
    while (s != NULL)
    {
        int c = checkSubstring(s->universityName, nam);
        if (c == 1)
            printf("\nUniversity Name:%s", s->universityName);

        s = s->unext;
    }
}

// chcek given substring is available or not............

int checkSubstring(char *str, char *search)
{
    int count1 = 0, count2 = 0, i, j, flag;

    while (str[count1] != '\0')
        count1++;
    while (search[count2] != '\0')
        count2++;
    for (i = 0; i <= count1 - count2; i++)
    {
        for (j = i; j < i + count2; j++)
        {
            flag = 1;
            if (str[j] != search[j - i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            break;
    }
    if (flag == 1)
        return 1;
    else
        return 2;

    return 0;
}

// Update the student list  bye cgpa .....

void update()
{
    struct student *s = start->snext;
    while (s != NULL)
    {
        if (s->cgpa < 6.0)
        {
            struct student *t, *sl = start->slnext, *p = (struct student *)malloc(sizeof(struct student));
            p->snext = NULL;
            p->branchId = s->branchId;
            p->cgpa = s->cgpa;
            p->roll = s->roll;
            strcpy(p->name, s->name);
            if (sl == NULL)
            {
                start->slnext = p;
            }
            else
            {
                while (sl->snext != NULL)
                {
                    sl = sl->snext;
                }
                sl->snext = p;
            }
            deleteStudent(s->roll);
        }
        s = s->snext;
    }
    struct student *sl = start->slnext;
    while (sl != NULL)
    {
        printf("Name: %s\n", sl->name);
        printf("Roll Number: %d\n", sl->roll);
        printf("CGPA: %0.4f\n", sl->cgpa);
        printf("BranchId: %d\n\n", sl->branchId);
        sl = sl->snext;
    }
}





// int checkBranch(int r, int u)
// {
//     struct branch *t;
//     t = start->bnext;
//     while (t->universityId != u)
//     {
//         t = t->bnext;
//     }
//     struct branchDetails *p;
//     p = t->bd;
//     while (p != NULL)
//     {
//         if (p->branchId == r)
//         {
//             return 2;
//             break;
//         }
//         p = p->bdnext;
//     }
//     if (p == NULL)
//         return 1;
// }
