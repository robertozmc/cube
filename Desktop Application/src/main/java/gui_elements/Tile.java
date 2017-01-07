package gui_elements;

import configuration.Configuration;
import javafx.animation.FadeTransition;
import javafx.animation.Interpolator;
import javafx.animation.ScaleTransition;
import javafx.animation.Timeline;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.util.Duration;
import scenes.MainScene;
import scenes.Scenes;
import sun.applet.Main;

/**
 * Created by Robert Kłódka on 09.04.2016.
 */
public class Tile extends Rectangle {

    public Tile(Color color) {
        new Rectangle();

        setWidth(Configuration.screenSize.getWidth()/4.5);
        setHeight(Configuration.screenSize.getWidth()/4.5);
        setFill(color);
    }

    private static void tileEnterAnimation(Tile tile) {

        ScaleTransition st = new ScaleTransition(Duration.millis(150), tile);
        st.setInterpolator(Interpolator.EASE_BOTH);
        st.setByX(0.1f);
        st.setByY(0.1f);
        st.setCycleCount(1);

        st.play();
    }

    private static void tileExitAnimation(Tile tile) {
        ScaleTransition st = new ScaleTransition(Duration.millis(150), tile);
        st.setInterpolator(Interpolator.EASE_BOTH);
        st.setByX(-0.1f);
        st.setByY(-0.1f);
        st.setCycleCount(1);

        st.play();
    }

    static void selectPanel(Tile panel, Scene scene) {
        Tile.tileEnterAnimation(panel);
//        Configuration.window.setScene(scene);
//        Configuration.level = 2;
    }

    static void deselectPanel(Scene scene, Tile tile) {
        if (scene == Scenes.mainScene) {
            Tile.tileExitAnimation(tile);
        }
        if (scene == Scenes.scene1) {
            // i tak dalej
        }

    }

}
