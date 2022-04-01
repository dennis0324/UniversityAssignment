public class Song {
    private String title;
    private String artist;
    private int year;
    private String country;

    Song(){
        this.title = "";
        this.artist = "";
        this.year = 2000;
        this.country = "";
    }
    Song(String title,String artist,int year,String country){
        this.title = title;
        this.artist = artist;
        this.year = year;
        this.country = country;
    }

    public void show(){
        System.out.println(this.year+"년 " +this.country+"의 "+this.artist+"가 부른 "+this.title);
    }
}
