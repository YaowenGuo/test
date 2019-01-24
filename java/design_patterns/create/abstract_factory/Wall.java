public class Wall implement MapSite {
    @Overwrite
    public bool enter() {
        return false;
    }
}
