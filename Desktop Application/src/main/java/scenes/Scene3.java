package scenes;

import configuration.Configuration;
import gui_elements.Tile;
import javafx.geometry.Insets;
import javafx.scene.layout.GridPane;

/**
 * Created by Robert Kłódka on 09.04.2016.
 */
public class Scene3 {

    //region Variables

        public static GridPane layout;

        // Tiles
        public static Tile panel_1_tile;
        public static Tile panel_2_tile;
        public static Tile panel_3_tile;
        public static Tile panel_4_tile;
        public static Tile panel_5_tile;

    //endregion

    public Scene3() {
        layout = new GridPane();

        layout.setPadding(new Insets(Configuration.tilePadding/4));
        layout.setHgap(Configuration.tilePadding);
        layout.setVgap(Configuration.tilePadding/4);

        // Active panels made of tiles
        panel_1_tile = new Tile(Configuration.BLUE);
        panel_2_tile = new Tile(Configuration.GREEN);
        panel_3_tile = new Tile(Configuration.RED);
        panel_4_tile = new Tile(Configuration.YELLOW);
        panel_5_tile = new Tile(Configuration.PURPLE);

        layout.add(panel_1_tile, 0, 0);
        layout.add(panel_2_tile, 1, 0);
        layout.add(panel_3_tile, 2, 0);
        layout.add(panel_4_tile, 0, 1);
        layout.add(new Tile(Configuration.TRANSPARENT), 1, 1);
        layout.add(panel_5_tile, 2, 1);
    }
}