#include <stdio.h>
#include <ctype.h>

const double under5 = 6.50;
const double under20 = 14.00;
const double base20 = 14.00;
const double extralb = 0.50;
const double price_artichokes = 2.05;
const double price_beets = 1.15;
const double price_carrots = 1.09;
const double DISCOUNT_RATE = 0.05;

int main(void)
{
    int ch;
    double lb_temp, lb_total;
    double cost_artichokes, cost_beets, cost_carrots;
    double cost_total, final_total, discount, shipping;
    double lb_artichokes = 0, lb_beets = 0, lb_carrots = 0;

    printf("Enter a to buy artichokes, b for beets, ");
    printf("c for carrots, q to quit: ");
    while ((ch = tolower(getchar())) != 'q')
    {
        if (isspace(ch))
        {
            continue;
        }
        while (getchar() != '\n')
            continue;
        switch (ch)
        {
            case 'a':
            {
                printf("Enter pounds of artichokes: ");
                scanf("%lf", &lb_temp);
                lb_artichokes += lb_temp;
                break;
            }
            case 'b':
            {
                printf("Enter pounds of beets: ");
                scanf("%lf", &lb_temp);
                lb_beets += lb_temp;
                break;
            }
            case 'c':
            {
                printf("Enter pounds of carrots: ");
                scanf("%lf", &lb_temp);
                lb_carrots += lb_temp;
                break;
            }
            default:
            {
                printf("%c is not a valid choice.\n", ch);
            }
        }
        printf("Enter a to buy artichokes, b for beets, ");
        printf("c for carrots, q to quit: ");
    }

    cost_artichokes = price_artichokes * lb_artichokes;
    cost_beets = price_beets * lb_beets;
    cost_carrots = price_carrots * lb_carrots;
    cost_total = cost_artichokes + cost_beets + cost_carrots;
    lb_total = lb_artichokes + lb_beets + lb_carrots;
    if (lb_total <= 0)
    {
        shipping = 0.0;
    }
    else if (lb_total < 5.0)
    {
        shipping = under5;
    }
    else if (lb_total < 20.0)
    {
        shipping = under20;
    }
    else
    {
        shipping = base20 + extralb * (lb_total - base20);
    }
    discount = (cost_total > 100.0 ? DISCOUNT_RATE * cost_total : 0.0);
    final_total = cost_total + shipping - discount;

    printf("Your order:\n");
    printf("%.2f lbs of artichokes at $%.2f per pound:$ %.2f\n",
           lb_artichokes, price_artichokes, cost_artichokes);
    printf("%.2f lbs of beets at $%.2f per pound: $%.2f\n",
           lb_beets, price_beets, cost_beets);
    printf("%.2f lbs of carrots at $%.2f per pound: $%.2f\n",
           lb_carrots, price_carrots, cost_carrots);
    printf("Total cost of vegetables: $%.2f\n", cost_total);
    if (cost_total > 100)
    {
        printf("Volume discount: $%.2f\n", discount);
    }
    printf("Shipping: $%.2f\n", shipping);
    printf("Total charges: $%.2f\n", final_total);

    return 0;
}
