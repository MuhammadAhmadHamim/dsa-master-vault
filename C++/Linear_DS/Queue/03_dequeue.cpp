class MyCircularDeque {
    private:
        int size;
        int* q;
        int f;
        int r;
        int count;
    public:
        MyCircularDeque(int k) {
            size = k;
            q = new int[k];
            f = 0;
            r = k - 1;
            count = 0; 
        }
        
        bool insertFront(int value) {
            if(isFull()){
                return false;
            }
    
            f = (f - 1 + size) % size;
            q[f]= value;
            count++;
            return true;
        }
        
        bool insertLast(int value) {
            if(isFull()){
                return false;
            }
    
            r = (r + 1) % size;
            q[r]= value;
            count++;
            return true;
        }
        
        bool deleteFront() {
            if (isEmpty()){
                return false;
            }
    
            f = (f + 1) % size;
            count--;
            return true;
        }
        
        bool deleteLast() {
            if (isEmpty()){
                return false;
            }
    
            r = (r - 1 + size) % size;
            count--;
            return true; 
        }
        
        int getFront() {
            if (isEmpty()){
                return -1;
            }
            return q[f];
        }
        
        int getRear() {
            if (isEmpty()){
                return -1;
            }
            return q[r]; 
        }
        
        bool isEmpty() {
            return (count == 0);
        }
        
        bool isFull() {
            return (count == size);
        }
    };