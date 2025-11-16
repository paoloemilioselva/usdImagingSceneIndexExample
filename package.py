name = 'usdImagingSceneIndexExample'

version = '0.0.1'

requires = [
    "usd-25",
    "cmake",
    "gcc",
]

cachable = False

def commands():
    env.PATH.prepend("{root}/bin")
    env.PXR_PLUGINPATH_NAME.prepend("{root}/plugins/IamHerePlugin/resources")
    env.PYTHONPATH.prepend("{root}/python")
    env.USDIMAGINGGL_ENGINE_ENABLE_SCENE_INDEX.set("True")
