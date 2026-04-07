#include<map>
#include<order.hpp>

class OrderBook
{
    private:
        std::map<double, Order>buyers; /*to store buyer in low buy price to high*/
        std::map<unsigned int, Order>buyer_register; /*to store each buy order to faciliate deletion nd search fast*/
        std::map<double, Order>seller; /*to store seller in low seller price to high seller*/
        std::map<unsigned int, Order>seller_register; /*to store each sell order to faciliate deletion nd search fast*/
    public:
        void insert(const Order &order);
        bool cancelOrder(unsigned int id);
        Order printBestBid();
        Order printBestAsk();

        private:
        bool match();
        bool trade(Order &buyerorder, Order &sellerorder);
};

