#ifndef array_H
#define array_H


#include <cassert>
    class intArray
    {

            private:
        int size_m{};
        int *arr{};
        
            public:
        intArray() = default;

        intArray(int lng): size_m(lng){
            assert(lng >=0);

            if(lng > 0)
                arr = new int[lng]{};
                 }

        ~intArray()
        {
            delete [] arr;
        }

        void erase()
        {
            delete [] arr;
            arr = nullptr;
            size_m = 0;
        }

        int& operator[](int index)
        {
             assert((index >= 0 && index < size_m));
            return arr[index];
        }

        void rellocate(int newLng)
        {
            erase();

            if(newLng < 0)
                return;
            
            arr = new int[newLng];
            size_m = newLng;
            
        }
        void resize(int NewLng)
        {
            if(NewLng == size_m)
            return;
            
            if(NewLng < 0)
            {
                erase();
                return;
            }

            int *NewArr{new int[NewLng]};
            if(size_m >0)
            {
                int elementsToCopy{(NewLng > size_m ? size_m : NewLng)};

                for(int count = 0; count < elementsToCopy; count++)
                    NewArr[count] = arr[count];
            }
            delete [] arr;
            size_m =  NewLng;
            arr = NewArr;
        }
        void insertBefore(int value, int index)
        {
            assert(index >= 0 && index <= size_m);

            int *NewArr{new int[size_m+1]};

            for(int count{0}; count < index; count++)
            {
                NewArr[count] = arr[count];
            }
            NewArr[index] = value;

            for(int count{index}; count < size_m; count++)
            {
                NewArr[count+1] = arr[count];
            }

            delete [] arr;
            arr = NewArr;
            size_m +=1;
        }
        void remove(int index )
        {
            assert(index >= 0 && index <= size_m);

            if(size_m == 1)
              {erase(); return; }

            int *NewArr{new int[size_m - 1]};

            for(int count{0}; count < index; count++)
                NewArr[count] = arr[count];

            for(int count{index+1}; count < size_m; count++)
                NewArr[count-1] = arr[count];
        
                delete [] arr;
                arr = NewArr;
                --size_m;
        }
        void change(int value, int index)
        {
            if(index < 0 || index > size_m)
            return;

            arr[index] = value;
        }
        int getLng() const {return size_m;}
    };


#endif