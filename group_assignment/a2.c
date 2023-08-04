#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int count = 0;
int count1 = 0;
struct shopcard
{
    int cardId, point, bd, bm, by, ltd, ltm, lty;
    char address[30], customerName[30];
    struct shopcard *snext;
};
struct toppoint
{
    struct shopcard *snext;
    struct toppoint *pnext;
};
struct item
{
    int itemId, price, quantity, catagory;
    char itemname[30];
    struct item *inext;
};

struct head_node
{
    struct shopcard *snext;
    struct item *inext;
    struct toppoint *pnext;
} *start = NULL;

void shopCardInfo();
void itemInfo();
void display();
int checkCard(int);
int checkitemId(int);
int checkQuantity(int, int);
void update();
void deleteCustomerLast();
int leapyear(int);
int calculateTime(int, int, int, int, int, int);
void purchase(int, int, int);
void purchaseAge(int, int, int);
void addpointlist(struct shopcard **);
void deletepointlist(int);
void delete (int);
int checkpoint(int);
int checkpointAge(int);

int main()
{
    int c, n = 1;

    while (n == 1)
    {
        printf("1.Add  customer information.\n2.Add item information.\n3.Display details.\n4.Update customer address.\n5.Delete customer details those last tranjection before 1 year.\n6.Purchase at offer date.\n7.Purchase at offer for age>60 .\n8.Exit.\n");
        printf("Enter the number which opertation you want: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
        {

            shopCardInfo();
            break;
        }
        case 2:
            itemInfo();
            break;
        case 3:
            display();
            break;
        case 4:
            update();
            break;
        case 5:
            deleteCustomerLast();
            break;
        case 6:
        {
            int pd, pm, py;
            printf("Enter the date of giving discount customer(day month year): ");
            scanf("%d %d %d", &pd, &pm, &py);
            purchase(pd, pm, py);
            break;
        }
        case 7:
        {
            int pd, pm, py;
            printf("Enter the date of giving discount customer those have age>60(day month year): ");
            scanf("%d %d %d", &pd, &pm, &py);
            purchaseAge(pd, pm, py);
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

// For Taking card information.............

void shopCardInfo()
{
    int cardId, point = 0, bd, bm, by, ltd, ltm, lty;
    char address[30], customerName[30];
    int r, bi, n = 1, c = 0;

    if (start == NULL)
    {
        struct head_node *head;
        head = (struct head_node *)malloc(sizeof(struct head_node));
        head->snext = NULL;
        head->inext = NULL;
        head->pnext = NULL;
        start = head;
    }
    while (n == 1)
    {
        struct shopcard *t, *p = (struct shopcard *)malloc(sizeof(struct shopcard));
        fflush(stdin);
        printf("Enter Customer name: ");
        gets(customerName);
        printf("Enter Customer address: ");
        gets(address);
        printf("Enter your CardId: ");
        scanf("%d", &cardId);
        printf("Enter the birthdate(day month year): ");
        scanf("%d %d %d", &bd, &bm, &by);
        printf("Enter the last transaction(day month year): ");
        scanf("%d %d %d", &ltd, &ltm, &lty);
        strupr(customerName);
        strupr(address);
        p->snext = NULL;
        p->cardId = cardId;
        p->bd = bd;
        p->bm = bm;
        p->by = by;
        p->lty = lty;
        p->ltm = ltm;
        p->ltd = ltd;
        strcpy(p->customerName, customerName);
        strcpy(p->address, address);
        if (start->snext == NULL)
        {
            start->snext = p;
        }
        else
        {
            int count = checkCard(p->cardId);
            if (count == 1)
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
                printf("You are not promoted for same cardID no.\n");
            }
        }
        printf("Press 1 to continue give another info || 0 to exit: ");
        scanf("%d", &n);
    }
}

// for checking card id is unique or not.................

int checkCard(int r)
{
    struct shopcard *t;
    t = start->snext;
    while (t != NULL)
    {
        if (t->cardId == r)
        {
            return 2;
            break;
        }
        t = t->snext;
    }
    if (t == NULL)
        return 1;
}

// for taking input of item details...............

void itemInfo()
{
    int itemId, price, quantity, catagory;
    char itemname[30];
    int n = 1;
    if (start == NULL)
    {
        struct head_node *head;
        head = (struct head_node *)malloc(sizeof(struct head_node));
        head->inext = NULL;
        head->snext = NULL;
        head->pnext = NULL;

        start = head;
    }
    while (n == 1)
    {
        struct item *t, *p = (struct item *)malloc(sizeof(struct item));
        fflush(stdin);
        printf("Enter itemID name: ");
        gets(itemname);
        fflush(stdin);
        strupr(itemname);
        printf("Enter itemID: ");
        scanf("%d", &itemId);
        printf("Enter item price: ");
        scanf("%d", &price);
        printf("Enter item quantity: ");
        scanf("%d", &quantity);
        printf("Enter item Catagory number(For Grocery(1)  For garments(2)  For electronics(3)): ");
        scanf("%d", &catagory);
        p->inext = NULL;
        p->itemId = itemId;
        p->price = price;
        p->quantity = quantity;
        p->catagory = catagory;
        strcpy(p->itemname, itemname);
        if (start->inext == NULL)
        {
            start->inext = p;
        }
        else
        {
            int count = checkitemId(p->itemId);
            if (count == 1)
            {
                t = start->inext;
                while (t->inext != NULL)
                {
                    t = t->inext;
                }
                t->inext = p;
            }
            else
                printf("Item is not promoted for same itemId.\n");
        }
        printf("Press 1 to continue give another info || 0 to exit: ");
        scanf("%d", &n);
    }
}

// for checking itemID is unique or not .......

int checkitemId(int r)
{
    struct item *t;
    t = start->inext;
    while (t != NULL)
    {
        if (t->itemId == r)
        {
            return 2;
            break;
        }
        t = t->inext;
    }
    if (t == NULL)
        return 1;
}

// display card details and item  details............

void display()
{
    struct shopcard *s = start->snext;
    struct item *u = start->inext;
    if (s == NULL)
        printf("There is no customer details in database.\n");
    else
    {
        printf("\nThe list of all customer details:\n");
        while (s != NULL)
        {
            printf("\nCustomerName: %s\n", s->customerName);
            printf("Address of customer: %s\n", s->address);
            printf("Shop CardId: %d\n", s->cardId);
            printf("Point: %d\n", s->point);
            printf("Birthdate: %d-%d-%d\n", s->bd, s->bm, s->by);
            printf("Last tranjection date: %d-%d-%d\n", s->ltd, s->ltm, s->lty);

            s = s->snext;
        }
    }
    if (u == NULL)
        printf("There is no item details in database.\n");
    else
    {
        printf("\nThe list of all item details:\n");
        while (u != NULL)
        {
            printf("\nItemName: %s\n", u->itemname);
            printf("ItemId: %d\n", u->itemId);
            printf("Price of item: %d\n", u->price);
            printf("Quantity of item: %d\n", u->quantity);
            u = u->inext;
        }
    }
}

// update customer address............

void update()
{
    int cid;
    char add[30];
    printf("Enter your cardId:");
    scanf("%d", &cid);
    fflush(stdin);
    printf("Enter your new address :");
    gets(add);
    struct shopcard *s = start->snext;
    while (s != NULL && s->cardId != cid)
    {
        s = s->snext;
    }
    if (s == NULL)
        printf("This card is not available.\n");
    else
        strcpy(s->address, add);
}

// delete card those have last tranjection before 1 year .........

void deleteCustomerLast()
{
    int py, pm, pd;

    printf("Enter the presentdate(day month year): ");
    scanf("%d %d %d", &pd, &pm, &py);
    struct shopcard *p = start->snext, *temp;
    while (p != NULL)
    {
        int c = calculateTime(p->ltd, p->ltm, p->lty, py, pm, pd);
        if (c > 1)
        {
            delete (p->cardId);
        }
        if (p != NULL)
            p = p->snext;
    }
}

// For caluclating purchase using point if it is same date compare to offer date and using point if satisfy all condition...........

void purchase(int dd, int dm, int dy)
{
    struct shopcard *st = start->snext;
    int ci, ii, n = 1, quantity, checkp, checkq, total = 0, cardI, temppoint, totalg = 0, totalga = 0, totale = 0, pd, pm, py;
    printf("Enter the date of purchase(day month year): ");
    scanf("%d %d %d", &pd, &pm, &py);
    printf("Enter your CardId: ");
    scanf("%d", &ci);
    cardI = checkCard(ci);
    if (cardI == 2)
    {
        while (n == 1)
        {
            printf("\nEnter your ItemId: ");
            scanf("%d", &ii);
            struct item *it = start->inext;

            while (it != NULL)
            {
                if (it->itemId == ii)
                {
                    printf("Enter how many want to purchase: ");
                    scanf("%d", &quantity);
                    if (it->quantity >= quantity)
                    {
                        if (it->catagory == 1)
                            totalg += ((it->price) * quantity);
                        else if (it->catagory == 2)
                            totalga += ((it->price) * quantity);
                        else
                            totale += ((it->price) * quantity);

                        it->quantity -= quantity;
                    }
                    else if (it->quantity == 0)
                        printf("This product is out of stock.\n");
                    else
                        printf("This product avilable amount is %d \n", it->quantity);

                    break;
                }
                it = it->inext;
            }
            if (it == NULL)
            {
                printf("This product is not avilable in our shop.\n");
            }
            printf("Press 1 if you want purchase another product || 0 to exit: ");
            scanf("%d", &n);
        }

        total = totale + totalg + totalga;
        temppoint = (totale / 100) * 10 + (totalga / 100) * 5 + (totalg / 100);
        printf("\nTotal amount of purchase in grocery: %d\n", totalg);
        printf("Total amount of purchase in Garments: %d\n", (totalga));
        printf("Total amount of purchase in electronics: %d\n", totale);
        checkp = checkpoint(ci);
        if (checkp == 2 && dd == pd && dm == pm && dy == py)
        {
            printf("You are able to use point.\nIf you want use press 1 || otherwise press any key:");
            int c1;
            scanf("%d", &c1);
            if (c1 == 1)
            {
                total -= (total * 10) / 100;
                while (st->cardId != ci)
                {

                    st = st->snext;
                }
                st->point = 0;
                count++;
                deletepointlist(ci);
            }
            else
            {
                while (st->cardId != ci)
                {

                    st = st->snext;
                }
                st->point += temppoint;
                if (st->point >= 1000)
                    addpointlist(&st);
            }
        }
        else
        {
            while (st->cardId != ci)
            {

                st = st->snext;
            }
            st->point += temppoint;
            if (st->point >= 1000)
                addpointlist(&st);
        }
        if (total == (totale + totalg + totalga))
        {
            printf("\nTotal amount of bill:  %d\n", total);
        }
        else
        {
            printf("\nTotal amount of purchase: %d\n", (totale + totalg + totalga));
            printf("Total amount of discount: %d\n", (totale + totalg + totalga - total));
            printf("Total amount of bill after using point: %d\n", total);
        }

        st->ltd = pd;
        st->ltm = pm;
        st->lty = py;
    }
    else
    {
        printf("Your cardID is not correct or add your details.\n");
    }
}

// For caluclating purchase using point if it is same date compare to offer date , get discout if his/her age is greater than 60 and using point if satisfy all condition...........

void purchaseAge(int dd, int dm, int dy)
{
    struct shopcard *st = start->snext;
    int ci, ii, n = 1, quantity, checkp, age, discount, total = 0, cardI, temppoint, totalg = 0, totalga = 0, totale = 0, pd, pm, py;
    printf("Enter the date of purchase(day month year): ");
    scanf("%d %d %d", &pd, &pm, &py);
    printf("Enter your CardId: ");
    scanf("%d", &ci);
    cardI = checkCard(ci);
    if (cardI == 2)
    {
        while (n == 1)
        {
            printf("\nEnter your ItemId: ");
            scanf("%d", &ii);
            struct item *it = start->inext;

            while (it != NULL)
            {
                if (it->itemId == ii)
                {
                    printf("Enter how many want to purchase: ");
                    scanf("%d", &quantity);
                    if (it->quantity >= quantity)
                    {
                        if (it->catagory == 1)
                            totalg += ((it->price) * quantity);
                        else if (it->catagory == 2)
                            totalga += ((it->price) * quantity);
                        else
                            totale += ((it->price) * quantity);

                        it->quantity -= quantity;
                    }
                    else if (it->quantity == 0)
                        printf("This product is out of stock.\n");
                    else
                        printf("This product avilable amount is %d \n", it->quantity);

                    break;
                }
                it = it->inext;
            }
            if (it == NULL)
            {
                printf("This product is not avilable in our shop.\n");
            }
            printf("Press 1 if you want purchase another product || 0 to exit: ");
            scanf("%d", &n);
        }

        total = totale + totalg + totalga;
        temppoint = (totale / 100) * 10 + (totalga / 100) * 5 + (totalg / 100);
        printf("\nTotal amount of purchase in grocery: %d\n", totalg);
        printf("Total amount of purchase in Garments: %d\n", (totalga));
        printf("Total amount of purchase in electronics: %d\n", totale);
        checkp = checkpointAge(ci);
        if (checkp == 2 && dd == pd && dm == pm && dy == py)
        {
            while (st->cardId != ci)
            {

                st = st->snext;
            }
            age = calculateTime(st->bd, st->bm, st->by, py, pm, py);
            if (age > 60)
                discount = (total * 15) / 100;

            st = start->snext;
            printf("You are able to use point.\nIf you want use press 1 || otherwise press any key:");
            int c1;
            scanf("%d", &c1);
            if (c1 == 1)
            {
                total -= (total * 10) / 100;
                while (st->cardId != ci)
                {

                    st = st->snext;
                }
                st->point = 0;
                count1++;
                deletepointlist(ci);
            }
            else
            {
                while (st->cardId != ci)
                {

                    st = st->snext;
                }
                st->point += temppoint;
                if (st->point >= 1000)
                    addpointlist(&st);
            }
        }
        else
        {
            while (st->cardId != ci)
            {

                st = st->snext;
            }
            st->point += temppoint;
            if (st->point >= 1000)
                addpointlist(&st);
        }
        if (total == (totale + totalg + totalga))
        {
            printf("\nTotal amount of bill:  %d\n", total);
        }
        else
        {
            printf("\nTotal amount of purchase: %d\n", (totale + totalg + totalga));
            if (age > 60)
                printf("Total amount of discount for age>60: %d\n", discount);
            printf("Total amount of discount for using point: %d\n", (totale + totalg + totalga - total));
            printf("Total amount of bill after using point: %d\n", (total - discount));
        }

        st->ltd = pd;
        st->ltm = pm;
        st->lty = py;
    }
    else
    {
        printf("Your cardID is not correct or add your details.\n");
    }
}

// for checking the person whose age is 60 , he is in the list of first accomulated 1000 points as well as his position is under 5 or not

int checkpointAge(int r)
{
    struct toppoint *t;
    t = start->pnext;
    int i = 1;
    while (t != NULL && i <= 5 - count1)
    {
        if (t->snext->cardId == r)
        {
            return 2;
            break;
        }
        t = t->pnext;
        i++;
    }
    if (t == NULL || (i == 5 - count1))
        return 1;
}

// add a customer in the list those got 1000 points.............

void addpointlist(struct shopcard **q)
{
    struct toppoint *t = start->pnext, *p;
    p = (struct toppoint *)malloc(sizeof(struct toppoint));
    p->pnext = NULL;
    p->snext = *q;
    if (start->pnext == NULL)
        start->pnext = p;
    else
    {
        while (t->pnext != NULL)
        {
            t = t->pnext;
        }
        t->pnext = p;
    }
}

// delete customer from the list(first getting 1000 point)  after got the service of using point..........

void deletepointlist(int cId)
{
    struct toppoint *p = start->pnext, *temp;

    if (p->snext->cardId == cId)
        start->pnext = p->pnext;
    else
    {
        while (p != NULL && p->snext->cardId != cId)
        {
            temp = p;
            p = p->pnext;
        }
        if (p != NULL)
            temp->pnext = p->pnext;
        free(p);
    }
}

// for checking the person who is in the list of first accomulated 1000 points as well as his position is under 10 or not

int checkpoint(int r)
{
    struct toppoint *t;
    t = start->pnext;
    int i = 1;
    while (t != NULL && i <= 10 - count)
    {
        if (t->snext->cardId == r)
        {
            return 2;
            break;
        }
        t = t->pnext;
        i++;
    }
    if (t == NULL || (i == 10 - count))
        return 1;
}

// delete customer card..........

void delete (int cId)
{
    struct shopcard *p = start->snext, *temp;

    if (p->cardId == cId)
        start->snext = p->snext;
    else
    {
        while (p != NULL && p->cardId != cId)
        {
            temp = p;
            p = p->snext;
        }
        if (p != NULL)
            temp->snext = p->snext;
    }
}

// check leap year............

int leapyear(int year)
{
    if ((year % 4 == 0) && ((year % 400 == 0) || (year % 100 != 0)))
        return 1;
    else
        return 0;
}

// calculate difference of two date(age)................

int calculateTime(int d, int m, int y, int py, int pm, int pd)
{
    int ay, am, ad;

    int q = 0;
    if (pd < d)
    {
        if (pm - 1 == 2)
        {
            int p = leapyear(py);
            if (p == 1)
                pd += 29;
            else
                pd += 28;
        }
        else if (pm == 0)
        {
            pm = 12;
            py -= 1;
            pd += 31;
        }
        else if ((pm - 1) % 2 == 0)
            pd += 31;
        else
            pd += 30;

        q = 1;
    }
    ad = pd - d;
    if (q == 1)
        pm -= 1;
    if (pm < m)
    {
        py -= 1;
        pm += 12;
    }
    am = pm - m;
    ay = py - y;

    if (ay > 60 || (ay == 60 && (am > 0 || ad > 0)))
        return ay + 1;
    else if (ay > 1 || (ay == 1 && (am > 0 || ad > 0)))
        return ay + 1;
    else
        return 0;
}
