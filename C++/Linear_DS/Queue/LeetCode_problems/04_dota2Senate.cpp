/*
In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. 
Now the Senate wants to decide on a change in the Dota2 game. 
The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

Ban one senator's right: A senator can make another senator lose all his rights in this and all the following rounds.
Announce the victory: If this senator found the senators who still have rights to vote are all from the same party,
he can announce the victory and decide on the change in the game.

Given a string senate representing each senator's party belonging.
The character 'R' and 'D' represent the Radiant party and the Dire party. 
Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last senator in the given order. 
This procedure will last until the end of voting.
All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party. 
Predict which party will finally announce the victory and change the Dota2 game. 
The output should be "Radiant" or "Dire".
*/
class Solution {
    public:
        string predictPartyVictory(string senate) {
            
            //Initializing 2 Queues to track the position of both parties 
            queue<int> radiant;
            queue<int> dire;
            
            //Saving the original size of an ever-changing senate string
            int n = senate.size();
            
            //Filling the position Queues
            for(int i=0 ; i < n ; i++){
                
                (senate[i]=='R') ? radiant.push(i) : dire.push(i);
            
            }

            //Iterating until either of them is zero
            while(!radiant.empty() && !dire.empty()){
                
                if(radiant.front() < dire.front()){ // If Radient is in-front
                    
                    radiant.push(radiant.front() + n); // Pushing the Radient with increased authority
                
                }

                else{ // If Radient is in-front
                
                    dire.push(dire.front() + n); // Pushing the Dire with increased authority
                
                }
                
                // Popping the element on-top of both Queues
                radiant.pop();
                dire.pop();
            
            }    
            
            return (radiant.empty()) ? "Dire" : "Radiant"; // Checking the Radient queue if empty, return Dire else Radient
        }
};