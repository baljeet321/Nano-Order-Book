class Order
{
    private:

        unsigned int id;
        double amount;
        unsigned int units;
        double unit_price;
    public:
        Order(unsigned id, double amount, unsigned int units);
        unsigned int getOrderId();
        double getAmount();
        unsigned int getUnits();
        unsigned int getUnitPrice();    
};