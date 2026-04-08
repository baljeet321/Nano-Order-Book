class Order
{
    private:

        unsigned int id;
        double amount;
        unsigned int units;
        double unit_price;
    public:
        Order(unsigned id, double amount, unsigned int units);
        unsigned int getOrderId() const;
        double getAmount();
        void setAmount(double amount);
        unsigned int getUnits();
        void setUnits(unsigned int units);
        unsigned int getUnitPrice() const;    
};