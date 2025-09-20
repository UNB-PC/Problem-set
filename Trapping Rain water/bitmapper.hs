{-# LANGUAGE OverloadedRecordDot #-}
{-# LANGUAGE NoFieldSelectors #-}
{-# LANGUAGE DuplicateRecordFields #-}
{-# LANGUAGE RecordWildCards #-}

import Data.Sequence qualified as Seq 
import Data.Sequence (Seq(..))

data State = MkState
  { leftMaximum :: Int
  , rightMaximum :: Int
  , waterTileCount :: Int
  , heightMap ::  Seq Int
  }
  deriving (Show, Eq)

createState :: [Int] -> State
createState height =
  let heightMap = Seq.fromList height
      leftMaximum :<| _ = heightMap
      _ :|> rightMaximum = heightMap
      waterTileCount = 0
  in MkState {..}

step :: State -> State
step state =
  if state.leftMaximum < state.rightMaximum
    then
      let left :<| heightMap = state.heightMap
          leftMaximum = max state.leftMaximum left
          rightMaximum = state.rightMaximum
          waterTileCount = state.waterTileCount + (leftMaximum - left)
      in MkState {..}
    else
      let heightMap :|> right = state.heightMap
          leftMaximum = state.leftMaximum
          rightMaximum = max state.rightMaximum right
          waterTileCount = state.waterTileCount + (rightMaximum - right)
      in MkState {..}

run :: State -> Int
run state =
  if Seq.null state.heightMap
    then state.waterTileCount
    else run $ step state

trap :: [Int] -> Int
trap =
  run . createState
