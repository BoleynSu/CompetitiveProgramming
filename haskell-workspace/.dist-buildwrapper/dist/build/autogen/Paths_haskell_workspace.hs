module Paths_haskell_workspace (
    version,
    getBinDir, getLibDir, getDataDir, getLibexecDir,
    getDataFileName
  ) where

import qualified Control.Exception as Exception
import Data.Version (Version(..))
import System.Environment (getEnv)
import Prelude

catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
catchIO = Exception.catch


version :: Version
version = Version {versionBranch = [0,1], versionTags = []}
bindir, libdir, datadir, libexecdir :: FilePath

bindir     = "C:\\Users\\boleynsu\\AppData\\Roaming\\cabal\\bin"
libdir     = "C:\\Users\\boleynsu\\AppData\\Roaming\\cabal\\haskell-workspace-0.1\\ghc-7.6.3"
datadir    = "C:\\Users\\boleynsu\\AppData\\Roaming\\cabal\\haskell-workspace-0.1"
libexecdir = "C:\\Users\\boleynsu\\AppData\\Roaming\\cabal\\haskell-workspace-0.1"

getBinDir, getLibDir, getDataDir, getLibexecDir :: IO FilePath
getBinDir = catchIO (getEnv "haskell_workspace_bindir") (\_ -> return bindir)
getLibDir = catchIO (getEnv "haskell_workspace_libdir") (\_ -> return libdir)
getDataDir = catchIO (getEnv "haskell_workspace_datadir") (\_ -> return datadir)
getLibexecDir = catchIO (getEnv "haskell_workspace_libexecdir") (\_ -> return libexecdir)

getDataFileName :: FilePath -> IO FilePath
getDataFileName name = do
  dir <- getDataDir
  return (dir ++ "\\" ++ name)
