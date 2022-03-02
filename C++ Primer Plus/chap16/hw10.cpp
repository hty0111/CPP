//
// Created by hty on 2021/9/3.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <memory>
using namespace std;

struct Review {
    string title;
    int rating;
    double price;
};

bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool sortAlpha(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool sortRating(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool sortPrice(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool fill(Review & r);
void showOpt();
void showSort(const shared_ptr<Review> & r);

int main()
{
    vector<shared_ptr<Review>> books;
    Review temp;
    while (fill(temp))
    {
        shared_ptr<Review> re (new Review(temp));
        books.push_back(re);
    }

    if (books.size() > 0)
    {
        cout << "Choose a way to show data: \n";
        showOpt();
        int choice;
        cin >> choice;
        while(choice > 0 && choice < 7)
        {
            switch (choice)
            {
                case 1:
                    for_each(books.begin(), books.end(), showSort);
                    break;
                case 2:
                    sort(books.begin(), books.end(), sortAlpha);
                    for_each(books.begin(), books.end(), showSort);
                    break;
                case 3:
                    sort(books.begin(), books.end(), sortRating);
                    for_each(books.begin(), books.end(), showSort);
                    break;
                case 4:
                    sort(books.begin(), books.end(), sortRating);
                    reverse(books.begin(), books.end());
                    for_each(books.begin(), books.end(), showSort);
                    break;
                case 5:
                    sort(books.begin(), books.end(), sortPrice);
                    for_each(books.begin(), books.end(), showSort);
                    break;
                case 6:
                    sort(books.begin(), books.end(), sortPrice);
                    reverse(books.begin(), books.end());
                    for_each(books.begin(), books.end(), showSort);
                    break;
                case 7:
                    break;
            }
            showOpt();
            cin >> choice;
        }
    }
}

bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
    if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else if (r1->title == r2->title && r1->rating == r2->rating && r1->price < r2->price)
        return true;
    else
        return false;
}

bool sortAlpha(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
    if (r1->title < r2->title)
        return true;
    else
        return false;
}

bool sortRating(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
    if (r1->rating< r2->rating)
        return true;
    else
        return false;
}

bool sortPrice(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
    if (r1->price < r2->price)
        return true;
    else
        return false;
}

bool fill(Review & r)
{
    cout << "Enter book title ('q' to quit): ";
    getline(cin, r.title);
    if (r.title == "q")
        return false;
    cout << "Enter book rating: ";
    cin >> r.rating;
    cout << "Enter book price: ";
    cin >> r.price;
    if (!cin)
        return false;
    while(cin.get() != '\n')
        continue;
    return true;
}

void showOpt()
{
    cout << "Please enter 1,2,3,4,5,6 or 7\n"
         << "1) by original order \t 2) by alphabet order  \n"
         << "3) by rating up      \t 4) by rating down     \n"
         << "5) by pricing up     \t 6) by pricing down    \n"
         << "7) quit  \n";
}

void showSort(const shared_ptr<Review> & r)
{
    cout << r->rating << "\t" << r->title << "\t" << r->price << endl;
}
