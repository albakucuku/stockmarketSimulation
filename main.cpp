
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Stock class
class Stock
{
public:
    string name;
    double price;
    double volatility;
    double dividends;

    Stock(string n, double p, double v, double d)
    {
        name = n;
        price = p;
        volatility = v;
        dividends = d;
    }

    void updatePrice(double marketFactor)
    {
        // Generate random price change (-volatility% to +volatility%)
        double change = ((double)rand() / RAND_MAX * 2.0 * volatility - volatility) / 100.0;

        // Update price based on market factor and price change
        price = price * (1.0 + marketFactor + change);
    }

    double getPrice()
    {
        return price;
    }
};

// Stock market simulation
int main()
{
    // Initialize random seed
    srand(time(0));

    // Create vector of stocks
    vector<Stock> stocks;
    stocks.push_back(Stock("AAPL", 100.00, 10.0, 2.0));
    stocks.push_back(Stock("GOOG", 200.00, 20.0, 4.0));
    stocks.push_back(Stock("MSFT", 300.00, 30.0, 6.0));
    stocks.push_back(Stock("IBM", 400.00, 40.0, 8.0));
    stocks.push_back(Stock("FB", 500.00, 50.0, 10.0));

    // Print starting prices
    cout << "--- Starting prices ---" << endl;
    for (int i = 0; i < stocks.size(); i++)
    {
        cout << stocks[i].name << ": $" << stocks[i].getPrice() << endl;
    }

    // Simulate stock market for 10 days
    const int NUM_DAYS = 10;
    for (int day = 1; day <= NUM_DAYS; day++)
    {
        cout << endl << "--- Day " << day << " ---" << endl;

        // Generate random market factor (-5% to +5%)
        double marketFactor = ((double)rand() / RAND_MAX * 10.0 - 5.0) / 100.0;

        // Update stock prices
        for (int i = 0; i < stocks.size(); i++)
        {
            stocks[i].updatePrice(marketFactor);

            // Print updated price
            cout << stocks[i].name << ": $" << stocks[i].getPrice() << endl;
        }
    }

    return 0;
}
