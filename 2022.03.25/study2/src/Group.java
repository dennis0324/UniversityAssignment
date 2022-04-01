public class Group {
    private Seat[] seats;
    private char type;

    Group(char type, int count){
        this.type = type;
        this.seats = new Seat[count];

        for(int i = 0; i < seats.length; i++){
            seats[i] = new Seat();
        }
    }

}
