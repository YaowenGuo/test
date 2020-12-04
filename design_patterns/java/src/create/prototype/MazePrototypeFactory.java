package create.prototype;

import java.util.HashMap;
import java.util.Map;

public class MazePrototypeFactory<T extends Object> {
    private Map<String, T> prototypeMap = new HashMap<>();
    public MazePrototypeFactory() {

    }

    public MazePrototypeFactory registerPrototype(String type, T prototype) {
        prototypeMap.put(type, prototype);
        return this;
    }

    public T clone(String type) {
        if (prototypeMap.containsKey(type)) {
            return (T) prototypeMap.get(type).clone();
        }
        return null;
    }
}
