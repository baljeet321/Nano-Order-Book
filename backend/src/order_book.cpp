#include "order_book.hpp"
#include <iostream>


OrderBook::OrderBook()
{
    buyers.clear();
    buyer_register.clear();
    seller.clear();
    seller_register.clear();
}

void OrderBook::insert(const Order &order, OrderType type)
{
    if(type == OrderType::BUY)
    {
        buyers.insert({{order.getUnitPrice(),order.getOrderId()},order});
        buyer_register.insert({order.getOrderId(), order});
    }
    else if(type == OrderType::SELL)
    {
        seller.insert({{order.getUnitPrice(),order.getOrderId()},order});
        seller_register.insert({order.getOrderId(), order}); 
    }
    if(match())
    {
        trade(getBestBid(), getBestAsk());
    }
}
void OrderBook::cancelOrder(unsigned int id)
{
    if(buyer_register.find(id)!=buyer_register.end())
    {
        Order temp = buyer_register[id];
        buyers.erase(std::make_pair(temp.getUnitPrice(), id));
        buyer_register.erase(id);
    }
    else if (seller_register.find(id)!=seller_register.end())
    {
        Order temp = buyer_register[id];
        seller.erase(std::make_pair(temp.getUnitPrice(), id));
        seller_register.erase(id);
    }
    else{
        std::cout<<"Order not exist with id : "<<id<<std::endl;
    }
    if(match())
    {
        trade(getBestBid(), getBestAsk());
    }
}

Order OrderBook::getBestBid()
{
    if(buyers.size()==0)
    {
        std::cout<<"No Order for buying stocks"<<std::endl;
        return;
    }
    /*buyer with maximum price*/
    auto it = prev(buyers.end());
    return it->second;
}

Order OrderBook::getBestAsk()
{
    /*Seller with lowest price*/
    if(seller.size() == 0)
    {
        std::cout<<"No order to sell stocks yet"<<std::endl;
    }
    return seller.begin()->second;
}

bool OrderBook::match()
{
    Order bestbid = getBestBid();
    Order bestAsk = getBestAsk();
    if(bestbid.getUnitPrice() >= bestAsk.getUnitPrice())
    {
        return true;
    }
    return false;
}

bool OrderBook::trade(Order buyerorder, Order sellerorder)
{
     unsigned int exch_units = std::min(buyerorder.getUnits(), sellerorder.getUnits());
     double buying_amounts = exch_units * buyerorder.getUnitPrice();
     double sellign_amounts = exch_units * sellerorder.getUnitPrice();

     buyerorder.setUnits(buyerorder.getUnits() - exch_units);
     buyerorder.setAmount(buyerorder.getAmount() - buying_amounts);
     sellerorder.setUnits(sellerorder.getUnits() - exch_units);

     if(buyerorder.getAmount() == 0 or buyerorder.getUnits() == 0)
     cancelOrder(buyerorder.getOrderId());

     if(sellerorder.getUnits()==0)
     {
        cancelOrder(sellerorder.getOrderId());
     }
}