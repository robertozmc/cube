package scenes;

import configuration.Configuration;
import gui_elements.Tile;
import javafx.geometry.Insets;
import javafx.scene.layout.GridPane;

/**
 * Created by Robert Kłódka on 09.04.2016.
 */
public class Scene4 {

    //region Variables

        public static GridPane layout;

        // Tiles
        public static Tile panel_1_tile;
        public static Tile panel_2_tile;
        public static Tile panel_3_tile;

    //endregion

    public Scene4() {
        layout = new GridPane();

        layout.setPadding(new Insets(Configuration.tilePadding/4));
        layout.setHgap(Configuration.tilePadding);
        layout.setVgap(Configuration.tilePadding/4);

        // Active panels made of tiles
        panel_1_tile = new Tile(Configuration.BLUE);
        panel_2_tile = new Tile(Configuration.GREEN);
        panel_3_tile = new Tile(Configuration.RED);

        layout.add(panel_1_tile, 0, 0);
        layout.add(panel_2_tile, 1, 0);
        layout.add(panel_3_tile, 2, 0);
    }
}