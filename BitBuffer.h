class BitBuffer{
    private:
        char bitBuff[8];
        int len;
        string ans;
        void flushBuff(){
            for(int i=0;i<len;i++){
                if(bitBuff[i]==48) ans+='0';
                else ans+='1';
            }
            len=0;
        }
        
    public:

        void print(){
            flushBuff();
            cout<<ans<<endl;
        }
    
        BitBuffer(){
            len = 0;
            ans = "";
        }

        void add(int z){
            bitBuff[len++] = 48 + z;
            if(len==8){ 
                flushBuff();
                
            }
        }

        void add(char x){
            add(0);
            for(int i=0;i<8;i++){
                if(x & 1){
                    add(1);
                }
                else{
                    add(0);
                }
                x>>=1;
            }
        }

        // jmax: 4096, lmax: 64
        void add(int j, int l){
            add(1);
            for(int i=0;i<12;i++){
                if(j&1){
                    add(1);
                }
                else{
                    add(0);
                }
                j>>=1;
            }

            for(int i=0;i<6;i++){
                if(l&1){
                    add(1);
                }
                else{
                    add(0);
                }
                l>>=1;
            }
        }
};
