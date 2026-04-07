A system that maintains a list of "Buy" and "Sell" orders for a single stock (e.g., "AAPL").

Requirement 1.1: I must be able to enter a New Order into the system.

Requirement 1.2: I must be able to Cancel an existing order so it no longer appears in the book.

Requirement 1.3: The system must automatically execute a Trade whenever a Buyer is willing to pay a price equal to or higher than what a Seller is asking.

## System Input
The system should accept commands from the console (keyboard) in this format:

BUY [ID] [Price] [Quantity]

SELL [ID] [Price] [Quantity]

CANCEL [ID]

## System Output (The Dashboard)
After every command I type, the system must print the current state of the market to the console. I need to see:

The Current Buy Orders (Sorted by Price).

The Current Sell Orders (Sorted by Price).

A notification if a Trade happened, including the Price and Quantity.

## Business Rules
Time Priority: If two people want to buy at the same price, the one who entered the order first must be traded with first.

Partial Fills: If a Buyer wants 100 shares but the Seller only has 40, the system should trade 40, remove the Seller, and leave the Buyer with 60 shares remaining in the book.
