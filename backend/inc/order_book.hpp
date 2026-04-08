#include<map>
#include <utility>

#include<order.hpp>
#include "order_type.hpp"

class OrderBook
{
    private:
        std::map < std::pair<double, unsigned int>, Order >  buyers; /*to store buyer in low buy price to high*/
        std::map<unsigned int, Order>buyer_register; /*to store each buy order to faciliate deletion nd search fast*/
        std::map<std::pair<double, unsigned int>, Order>seller; /*to store seller in low seller price to high seller*/
        std::map<unsigned int, Order>seller_register; /*to store each sell order to faciliate deletion nd search fast*/
    public:
        OrderBook();
        void insert(const Order &order, OrderType type);
        void cancelOrder(unsigned int id);
        Order getBestBid();
        Order getBestAsk();

        private:
        bool match();
        bool trade(Order buyerorder, Order sellerorder);
};

