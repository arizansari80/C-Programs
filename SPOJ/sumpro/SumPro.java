import java.io.DataInputStream;
import java.io.IOException;

class FastReader{
	private final int SIZE=1<<16;
	private DataInputStream di;
	private int bufferPointer,bytesRead;
	private byte[] buffer;

	public FastReader(){
		di=new DataInputStream(System.in);
		buffer=new byte[SIZE];
		bufferPointer=bytesRead=0;
	}

	public int getInt() throws IOException{
		int ret=0;
		byte c;
		c=read();
		while(c>=48){
			ret=ret*10+c-48;
			c=read();
		}
		return ret;
	}

	private void fillBuffer() throws IOException{
		bytesRead=di.read(buffer,bufferPointer=0,SIZE);
		if(bytesRead==-1)
			buffer[0]=-1;
	}

	private byte read() throws IOException{
		if(bufferPointer==bytesRead)
			fillBuffer();
		return buffer[bufferPointer++];
	}
}

public class SumPro{
	public static void main(String[] args) throws IOException{
		FastReader fi=new FastReader();
		int tc=fi.getInt();
		int[] n=new int[tc];
		int mod=1000000007;
		for(int i=0;i<tc;i++)
			n[i]=fi.getInt(); 
		int sum=0,m;
		if(n[0]%2==0)
			m=n[0]/2;
		else
			m=n[0]/2+1;
		sum=(m*(m-1))/2;
		for(int i=1;i<=n[0]/2;i++)
			sum+=n[0]%i;
		int res=n[0]*n[0]-sum;
		System.out.println(res);
	}
}