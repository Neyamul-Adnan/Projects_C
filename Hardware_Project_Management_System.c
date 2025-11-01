/*
Authors : Tamim Tareq Ahmed Siam [2025-2-60-480]
          Anik Roy Ankon [2025-2-60-491]
          Neyamul Adnan [2025-2-60-476]

Project : Hardware Product Management System
Date    : 31/08/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define username "cse103"
#define password "103"

void login();
void print_header(char title[]);
void add_product();
void delete_product();
void dlt_name();
void dlt_code();
void edit_product();
void edt_name();
void edit_code();
void search_product();
void src_name();
void src_code();
void list_product();
void sell_product();
void sell_name();
void sell_code();
void print_receipt();

typedef struct product_details
{
    char name[100];
    int id;
    int p_price;
    int s_price;
    int quantity;

} pd;

pd p[100];
int total_pdt = 0;

int main()
{
    login();

    int n;
    char temp[100];

    do
    {
        print_header("MAIN MENU");
        printf("1. Add Product\n");
        printf("2. Edit Product\n");
        printf("3. Delete Product\n");
        printf("4. Search Product\n");
        printf("5. List Products\n");
        printf("6. Sell Product\n");
        printf("7. Exit\n");
        printf("\nEnter any choice: ");
        fgets(temp, sizeof(temp), stdin);
        sscanf(temp, "%d", &n);

        system("cls");

        switch (n)
        {
        case 1:
            print_header("ADD PRODUCT");
            add_product();
            break;
        case 2:
            print_header("EDIT PRODUCT");
            edit_product();
            break;
        case 3:
            print_header("DELETE PRODUCT");
            delete_product();
            break;
        case 4:
            print_header("SEARCH PRODUCT");
            search_product();
            break;
        case 5:
            print_header("ALL PRODUCT LIST");
            list_product();
            break;
        case 6:
            print_header("SELL PRODUCT");
            sell_product();
            break;

        default:
            break;
        }

    } while (n != 7);

    return 0;
}
void print_header(char title[])
{
    system("cls");

    printf("\n\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
    printf("\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
    printf("\t<><><><><><><>                                              <><><><><><><>\n");
    printf("\t<><><><><><><>      Hardware Product Management System      <><><><><><><>\n");
    printf("\t<><><><><><><>                                              <><><><><><><>\n");
    printf("\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
    printf("\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");

    printf("\n\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
    printf("\t                              %s\n", title);
    printf("\t<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n");
}
void login()
{
    char u_name[50], pass[50];

    while (1)
    {
        system("cls");
        print_header("PLEASE LOGIN FIRST");
        printf("Enter username: ");
        fgets(u_name, 50, stdin);
        u_name[strcspn(u_name, "\n")] = 0;

        printf("Password: ");
        fgets(pass, 50, stdin);
        pass[strcspn(pass, "\n")] = 0;

        if (strcmp(u_name, username) == 0 && strcmp(pass, password) == 0)
        {
            printf("\nLogin successful!\n");
            system("cls");
            break;
        }
    }
}
void add_product()
{
    char temp[100];
    int a;
    do
    {
        print_header("ADD PRODUCT");
        printf("\nEnter Product name: ");
        fgets(p[total_pdt].name, 100, stdin);
        p[total_pdt].name[strcspn(p[total_pdt].name, "\n")] = 0;

        printf("Enter Product ID: ");
        fgets(temp, 100, stdin);
        sscanf(temp, "%d", &p[total_pdt].id);

        printf("Enter Product purchase price: ");
        fgets(temp, 100, stdin);
        sscanf(temp, "%d", &p[total_pdt].p_price);

        printf("Enter Product selling price: ");
        fgets(temp, 100, stdin);
        sscanf(temp, "%d", &p[total_pdt].s_price);

        printf("Enter Product quantity: ");
        fgets(temp, 100, stdin);
        sscanf(temp, "%d", &p[total_pdt].quantity);
        total_pdt++;
        printf("\n_____PRODUCT SUCCESSFULLY ADDED_____\n");

        printf("\nEnter 1 to add another product or 0 to go back: ");
        fgets(temp, 100, stdin);
        sscanf(temp, "%d", &a);
        if (a == 1)
            system("cls");

    } while (a == 1);
}
void delete_product()
{
    int n;
    char temp[100];

    print_header("DELETE PRODUCT");
    printf("_____Search by name or code to delete_____\n");
    printf("1. Product Name \n");
    printf("2. Product Code \n");
    printf("\nChoose 1 or 2 : ");
    fgets(temp, 100, stdin);
    sscanf(temp, "%d", &n);

    switch (n)
    {
    case 1:
        system("cls");
        dlt_name();
        break;
    case 2:
        system("cls");
        dlt_code();
        break;
    default:
        printf("Invalid choice!\n");
        break;
    }
}
void dlt_name()
{
    char name[100];
    int x, found = 0;
    char temp[100];

    print_header("DELETE PRODUCT");

    if (total_pdt > 0)
        while (getchar() != '\n')
            ;

    printf("Enter the product Name: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < total_pdt; i++)
    {
        if (strcmp(name, p[i].name) == 0) // compare: (2nd one - 1st one)= +ve num else neg or equal = 0
        {
            printf("\n----- PRODUCT FOUND -----\n");
            printf("Product Name                : %s\n", p[i].name);
            printf("Product ID                  : %d\n", p[i].id);
            printf("Product Quantity            : %d\n", p[i].quantity);
            printf("-----------------------------------------------------------\n");

            printf("Are you sure you want to delete this product?\n");
            printf("1. YES\n");
            printf("2. NO\n");
            printf("Enter Choice : ");
            fgets(temp, 100, stdin);
            sscanf(temp, "%d", &x);

            if (x == 1)
            {
                for (int j = i; j < total_pdt - 1; j++)
                {
                    p[j] = p[j + 1]; // left shift
                }
                total_pdt--;
                printf("\n-----PRODUCT DELETED SUCCESSFULLY-----\n");
            }
            else
            {
                printf("\n-----DELETION CANCELED-----\n");
            }

            found = 1;
            break;
        }
    }
    if (found != 1)
        printf("\n-----PRODUCT NOT FOUND-----\n");

    printf("\nEnter 1 to delete another product or 0 for MAIN MENU: ");
    fgets(temp, 100, stdin);
    sscanf(temp, "%d", &x);

    if (x == 1)
    {
        system("cls");
        delete_product();
    }
    else
    {
        system("cls");
        return;
    }
}
void dlt_code()
{
    int code, x, found = 0;
    char temp[100];
    print_header("DELETE PRODUCT");
    printf("Enter the product code: ");
    fgets(temp, 100, stdin);
    sscanf(temp, "%d", &code);
    for (int i = 0; i < total_pdt; i++)
    {
        if (code == p[i].id)
        {
            printf("\n----- PRODUCT FOUND -----\n");
            printf("Product Name                : %s\n", p[i].name);
            printf("Product ID                  : %d\n", p[i].id);
            printf("Product Quantity            : %d\n", p[i].quantity);
            printf("-----------------------------------------------------------\n");
            printf("Are you sure you want to delete this product?\n");
            printf("1. YES\n");
            printf("2. NO\n");
            printf("Enter Choice : ");
            fgets(temp, 100, stdin);
            sscanf(temp, "%d", &x);
            if (x == 1)
            {
                for (int j = i; j < total_pdt - 1; j++)
                {
                    p[j] = p[j + 1]; // left shift
                }
                total_pdt--;
                printf("\n-----PRODUCT DELETED SUCCESSFULLY-----\n");
            }
            else
                printf("\n-----DELETION CANCELED-----\n");
            found = 1;
            break;
        }
    }
    if (found != 1)
        printf("\n-----PRODUCT NOT FOUND-----\n");
    printf("\nEnter 1 to delete another product or 0 for MAIN MENU: ");
    fgets(temp, 100, stdin);
    sscanf(temp, "%d", &x);
    if (x == 1)
    {
        system("cls");
        delete_product();
    }
    else
    {
        system("cls");
        return;
    }
}
void edit_product()
{
    int n;
    char temp[100];

    system("cls");
    print_header("EDIT PRODUCT");

    printf("\n==========Search Product by==========\n");
    printf("1.Product name \n");
    printf("2.Product ID \n");
    printf("Enter choice 1 or 2:");
    fgets(temp, 100, stdin);
    sscanf(temp, "%d", &n);

    switch (n)
    {
    case 1:
        system("cls");
        edt_name();
        break;

    case 2:
        system("cls");
        edit_code();
        break;
    default:
        printf("Invalid choice!\n");
    }
}
void edt_name()
{
    char name[100], temp[100];
    int x, found = 0;

    print_header("EDIT PRODUCT");

    printf("Enter Product Name: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < total_pdt; i++)
    {
        if (strcmp(name, p[i].name) == 0)
        {
            printf("\n----- PRODUCT FOUND -----\n");
            printf("\nProduct Name     : %s", p[i].name);
            printf("\nProduct ID       : %d", p[i].id);
            printf("\nPurchase Price   : %d", p[i].p_price);
            printf("\nSelling Price    : %d", p[i].s_price);
            printf("\nProduct Quantity : %d\n", p[i].quantity);
            printf("----------------------------------------\n");

            printf("Enter new name: ");
            fgets(p[i].name, 100, stdin);
            p[i].name[strcspn(p[i].name, "\n")] = 0;

            printf("Enter new purchase price: ");
            fgets(temp, 100, stdin);
            sscanf(temp, "%d", &p[i].p_price);

            printf("Enter new selling price: ");
            fgets(temp, 100, stdin);
            sscanf(temp, "%d", &p[i].s_price);

            printf("Enter new quantity: ");
            fgets(temp, 100, stdin);
            sscanf(temp, "%d", &p[i].quantity);

            printf("\nProduct Updated!\n");
            found = 1;
            break;
        }
    }
    if (found != 1)
    {
        printf("\n-----PRODUCT NOT FOUND-----\n");
    }

    printf("\n\nEnter 1 to edit another product or enter 0 for Main Menu\n\n");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%d", &x);

    if (x == 1)
    {
        system("cls");
        edit_product();
    }
    else
    {
        system("cls");
        return;
    }
}
void edit_code()
{
    int x, code, found = 0;
    char temp[100];

    print_header("EDIT PRODUCT");

    printf("Enter Product ID: ");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%d", &code);

    for (int i = 0; i < total_pdt; i++)
    {
        if (code == p[i].id)
        {
            printf("\n----- PRODUCT FOUND -----\n");
            printf("\nProduct Name     : %s", p[i].name);
            printf("\nProduct ID       : %d", p[i].id);
            printf("\nPurchase Price   : %d", p[i].p_price);
            printf("\nSelling Price    : %d", p[i].s_price);
            printf("\nProduct Quantity : %d\n", p[i].quantity);
            printf("----------------------------------------\n");

            printf("Enter new name: ");
            fgets(p[i].name, 100, stdin);
            p[i].name[strcspn(p[i].name, "\n")] = 0;

            printf("Enter new purchase price: ");
            fgets(temp, 100, stdin);
            sscanf(temp, "%d", &p[i].p_price);

            printf("Enter new selling price: ");
            fgets(temp, 100, stdin);
            sscanf(temp, "%d", &p[i].s_price);

            printf("Enter new quantity: ");
            fgets(temp, 100, stdin);
            sscanf(temp, "%d", &p[i].quantity);

            printf("\nProduct Updated!\n");
            found = 1;
            break;
        }
    }
    if (found != 1)
    {
        printf("\n-----PRODUCT NOT FOUND-----\n");
    }

    printf("\n\nEnter 1 to edit another product or enter 0 for Main Menu\n\n");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%d", &x);

    if (x == 1)
    {
        system("cls");
        edit_product();
    }
    else
    {
        system("cls");
        return;
    }
}
void search_product()
{
    int n;
    char temp[100];
    print_header("SEARCH PRODUCT");

    printf("_____Search by_____\n");
    printf("1. Product Name \n");
    printf("2. Product Code \n");
    printf("\nChoose 1 or 2 : ");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%d", &n);

    switch (n)
    {
    case 1:
        system("cls");
        src_name();
        break;
    case 2:
        system("cls");
        src_code();
        break;
    }
}
void src_name()
{
    char name[100], temp[100];
    int x, found = 0;
    int prd_count = total_pdt;

    print_header("SEARCH PRODUCT");

    printf("Enter the product Name: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = 0;
    for (int i = 0; i < prd_count; i++)
    {
        if (strcmp(name, p[i].name) == 0) // compare: (2nd one - 1st one)= +ve num else neg or equal = 0
        {
            printf("\n----- PRODUCT FOUND -----\n");
            printf("Product Name                : %s\n", p[i].name);
            printf("Product ID                  : %d\n", p[i].id);
            printf("Product Purchase Price      : %.d\n", p[i].p_price);
            printf("Product Selling Price       : %.d\n", p[i].s_price);
            printf("Product Quantity            : %d\n", p[i].quantity);
            printf("Product Stock Value         : %d\n", p[i].quantity * p[i].p_price);
            printf("Product Stock Sale Value    : %d\n", p[i].quantity * p[i].s_price);
            found = 1;
            break;
        }
    }
    if (found != 1)
    {
        printf("\n-----PRODUCT NOT FOUND-----\n");
    }

    printf("\n\nEnter 1 to search another product or enter 0 for Main Menu\n\n");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%d", &x);

    if (x == 1)
    {
        system("cls");
        search_product();
    }
    else
    {
        system("cls");
        return;
    }
}
void src_code()
{
    int code, x, found = 0;
    int prd_count = total_pdt;
    char temp[100];

    print_header("SEARCH PRODUCT");
    printf("Enter the product code: ");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%d", &code);

    for (int i = 0; i < prd_count; i++)
    {
        if (code == p[i].id)
        {
            printf("\n----- PRODUCT FOUND -----\n");
            printf("Product Name                : %s\n", p[i].name);
            printf("Product ID                  : %d\n", p[i].id);
            printf("Product Purchase Price      : %.d\n", p[i].p_price);
            printf("Product Selling Price       : %.d\n", p[i].s_price);
            printf("Product Quantity            : %d\n", p[i].quantity);
            printf("Product Stock Value         : %d\n", p[i].quantity * p[i].p_price);
            printf("Product Stock Sale Value    : %d\n", p[i].quantity * p[i].s_price);
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("\n-----PRODUCT NOT FOUND-----\n");
    }

    printf("\n\nEnter 1 to search another product or enter 0 for Main Menu\n\n");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%d", &x);

    if (x == 1)
    {
        system("cls");
        search_product();
    }
    else
    {
        system("cls");
        return;
    }
}
void list_product()
{
    char temp[10];

    if (total_pdt == 0)
    {
        printf("\nNo products available!\n");
        printf("\nPress Enter to return to MAIN MENU...");
        fgets(temp, sizeof(temp), stdin);
        return;
    }

    printf("\n____________PRODUCT LIST____________\n");
    for (int i = 0; i < total_pdt; i++)
    {
        printf("\nProduct Name     : %s", p[i].name);
        printf("\nProduct ID       : %d", p[i].id);
        printf("\nPurchase Price   : %d", p[i].p_price);
        printf("\nSelling Price    : %d", p[i].s_price);
        printf("\nProduct Quantity : %d\n", p[i].quantity);
        printf("----------------------------------------\n");
    }

    printf("\nPress Enter to return to MAIN MENU...");
    fgets(temp, sizeof(temp), stdin);
}
void sell_product()
{
    int n;
    char temp[100];

    print_header("SELL PRODUCT");

    printf("_____Search by name or code to sell_____\n");
    printf("1. Product Name \n");
    printf("2. Product Code \n");
    printf("\nChoose 1 or 2 : ");
    fgets(temp, 100, stdin);
    sscanf(temp, "%d", &n);

    switch (n)
    {
    case 1:
        system("cls");
        sell_name();
        break;
    case 2:
        system("cls");
        sell_code();
        break;
    default:
        printf("Invalid choice!\n");
    }
}
void sell_name()
{
    char name[100], temp[100];
    int q, x, found = 0;

    do
    {
        print_header("SELL PRODUCT");

        printf("Enter the product Name: ");
        fgets(name, 100, stdin);
        name[strcspn(name, "\n")] = 0;

        for (int i = 0; i < total_pdt; i++)
        {
            if (strcmp(name, p[i].name) == 0)
            {
                printf("\n-----------------------------------------------------------\n");
                printf("Product Name                : %s\n", p[i].name);
                printf("Product ID                  : %d\n", p[i].id);
                printf("Product Selling Price       : %.d\n", p[i].s_price);
                printf("Product Quantity            : %d\n", p[i].quantity);
                printf("-----------------------------------------------------------\n");
                printf("Enter Selling Quantity      : ");
                fgets(temp, 100, stdin);
                sscanf(temp, "%d", &q);

                if (q > p[i].quantity)
                {
                    printf("Not enough stock!\n");
                }
                else
                {
                    p[i].quantity -= q;
                    print_receipt(p[i].name, p[i].s_price, q);
                }
                found = 1;
                break;
            }
        }
        if (found != 1)
        {
            printf("\n-----PRODUCT NOT FOUND-----\n");
        }

        printf("\nEnter:\n 1 to sell another product \n 0 for MAIN MENU: ");
        fgets(temp, 100, stdin);
        sscanf(temp, "%d", &x);

        if (x == 0)
        {
            return;
        }
    } while (x == 1);
    system("cls");
}
void sell_code()
{
    int code, x, q, found = 0;
    char temp[100];

    print_header("SELL PRODUCT");

    printf("Enter the product code: ");
    fgets(temp, 100, stdin);
    sscanf(temp, "%d", &code);

    for (int i = 0; i < total_pdt; i++)
    {
        if (code == p[i].id)
        {
            printf("\n-----------------------------------------------------------\n");
            printf("Product Name                : %s\n", p[i].name);
            printf("Product ID                  : %d\n", p[i].id);
            printf("Product Selling Price       : %.d\n", p[i].s_price);
            printf("Product Quantity            : %d\n", p[i].quantity);
            printf("-----------------------------------------------------------\n");
            printf("Enter Selling Quantity      : ");
            fgets(temp, 100, stdin);
            sscanf(temp, "%d", &q);

            if (q > p[i].quantity)
            {
                printf("Not enough stock!\n");
            }
            else
            {
                p[i].quantity -= q;
                print_receipt(p[i].name, p[i].s_price, q);
            }
            found = 1;
            break;
        }
    }
    if (found != 1)
    {
        printf("\n-----PRODUCT NOT FOUND-----\n");
    }
    printf("\n\nEnter 1 to sell another product or enter 0 for MAIN MENU\n\n");
    fgets(temp, 100, stdin);
    sscanf(temp, "%d", &x);

    if (x == 1)
    {
        system("cls");
        sell_product();
    }
    else
    {
        system("cls");
        return;
    }
}
void print_receipt(char name[], int price, int q)
{
    int paid = 0, total = (price * q);
    float vat = 0.0, grand_total = total;
    char temp[100];

    system("cls");

    printf("====================================\n");
    printf("            Hardware Shop\n");
    printf("       12/B, Gulshan 2, Dhaka\n");
    printf("          VAT No: 2342526334\n");
    printf("====================================\n");
    printf("Item Name        : %s\n", name);
    printf("Price per Item   : %d\n", price);
    printf("Quantity         : %d\n", q);
    printf("Total            : %d\n", total);
    printf("VAT              : %.2f\n", vat);
    printf("Grand Total      : %.2f\n", grand_total);
    printf("------------------------------------\n");

    printf("Paid Amount      : ");
    fgets(temp, 100, stdin);
    sscanf(temp, "%d", &paid);
    printf("Return           : %.2f\n", (float)paid - grand_total);

    printf("====================================\n");
    printf("           THANK YOU\n");
    printf("       Please Come Again\n");
    printf("====================================\n");
}
