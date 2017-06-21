using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;

public class TizenExtension : MonoBehaviour {

    public UnityEngine.UI.Text Description;
    public delegate void RotateAction(int rot);
    public static event RotateAction onRotate;

#if (UNITY_TIZEN && !UNITY_EDITOR)
    // Use this for initialization

    void Awake () {
        Debug.Log("Starting tizen plugin: "+tizenSetup());
    }

    // Update is called once per frame
    void Update () {
        int dir  = getDir();
        if (dir != 0 && onRotate != null)
        {
            onRotate(dir);
            resetDir();
        }
    }
#endif

#if UNITY_EDITOR
    void Awake()
    {
        Debug.Log("Starting tizen backend plugin");
    }

    private void Update()
    {
        if (Input.GetKeyUp(KeyCode.E))
        {
            if (onRotate != null)
            {
                onRotate(-1);
            }
        }
        else if (Input.GetKeyUp(KeyCode.Q))
        {
            onRotate(1);
        }
    }
#endif



#if (UNITY_TIZEN && !UNITY_EDITOR)
    [DllImport("bezelplugin")]
    private static extern int tizenSetup();

    [DllImport("bezelplugin")]
    private static extern int getDir();

    [DllImport("bezelplugin")]
    private static extern void resetDir();
#endif


}


