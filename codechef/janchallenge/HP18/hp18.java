import java.util.*;

// import com.sun.java.swing.plaf.motif.MotifBorders.FrameBorder;
// import com.sun.tools.sjavac.comp.dependencies.PublicApiCollector;

public class hp18{
    public static void main(String Args[]){
        Scanner inp = new Scanner(System.in);
        int t=inp.nextInt();
        for(;t>0;t--){
            int n,a,b;
            n=inp.nextInt();
            a=inp.nextInt();//for bob 
            b=inp.nextInt();//for alice
            int[] arr=new int[n];
            int flag=0;
            int c=0;
            int size=0;
            for(int i=0;i<n;i++){
                int temp=inp.nextInt();
                if(temp%a!=0){
                    arr[c]=temp;
                    c++;
                }
            } 
            
            if(c!=n){
                flag++;
                size=c;
            }
            
            //bob had the first chance up here
            //we do it for alice again
            if(flag==1){
                c=0;
                for(int i=0;i<size;i++){//if there are no further elements in the array bob wins.
                    int temp=arr[i]; 
                    if(temp%b!=0){
                        arr[c]=temp;
                        c++;
                    }
                } 
                if(c!=size){
                    flag++;
                    size=c;
                }
            }
            //this was the chance of alice
            //again chance of bob
            if(flag==2){
                c=0;
                for(int i=0;i<size && flag==2;i++){//if no further elements to be removed by bob then alice wins
                    int temp=arr[i];
                    if(temp%a!=0){
                        arr[c]=temp;
                        c++;
                    }
                } 
                if(c!=size){
                    flag++;
                    size=c;
                }
            }
            // display(arr,size);
            //if flag=1,3 --bob
            //if flag=2 --alice

            if(flag%2==0){
                System.out.println("ALICE");
            }
            else{
                System.out.println("BOB");
            }
        }
    }
    public static void display(int[] arr,int n){
        for(int i=0;i<n;i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}