public class LongestSong implements Command
{
	
	private Song longestSong;
	private int songLength;
	
	public LongestSong()
	{
		longestSong = null;
		songLength = 0;
	}
	
	public void execute(Object item)
	{
		CD cd = (CD) item;
		
		for(int i = 0; i < cd.getNumberOfTracks(); i++)
		{
			Song song = 
			if(song.getLength() > songLength)
			{
				//update longestSong & songLength
				
				
			}
		}
		
	}
	
	public Song getLongestSong()
	{
		
	}
}