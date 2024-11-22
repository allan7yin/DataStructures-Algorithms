'''
How to design an elevator system:
----------------------------------
(1) An elevator will move in one direction until all those requests have been processed

The simple, and rather ineffecient method, is for the elevator to operate in a FIFO order,
so whoever first clicks on the elevator, goes inside, and enters their destination, and we
will process in that order

(2) Optimizing Elevator paths
The more effecient method, is to collect all people along the way in a certain direction,
as long as there are requests coming in, we will try to accomodate every one we can
while moving in a certain direction

The first option should be very straightforward:
    - maintain a queue of requests, which could be tuple, or custom class, of some data
    - then, we will move the elevator to process those requests in a FIFO order

The second option is more complex, and more cases we need to consider:
    - we will categorize the requests into "up" and "down" ones
    - for the ones going up, we will add them to the "up" list. This list needs
      to be sorted, so we do O(n) request insertions

    - We also maintain a counter for how many people we need to service in this up journey. We only
      increment this counter if the person requesting elevator is above the elevator
      current level. Otherwise, we just add it to the list. Once the counter is 0,
      and there are no people trying to go in the same direction us, that are above us,
      then we switc directions, and go to the highest "down" person, and repeat the
      same process

--> This is not Leetcode, do not be scared to sort the data, always find solution before
looking to optimize
'''
class Elevator:
