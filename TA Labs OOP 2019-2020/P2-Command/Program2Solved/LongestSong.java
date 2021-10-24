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
			Song song = cd.getSong(i);
			if(song.getLength() > songLength)
			{
				this.longestSong = song;
				this.songLength = song.getLength();
			}
		}
		
	}
	
	public Song getLongestSong()
	{
		return longestSong;
	}
}