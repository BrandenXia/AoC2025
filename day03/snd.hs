module Main where

import Data.Char (digitToInt)
import Data.Foldable (maximumBy)

fmax :: [Int] -> Int
fmax xs =
  let cmp (i1, x1) (i2, x2) = compare x1 x2 <> compare i2 i1
      step (prev, pidx) curr = (prev * 10 + e, idx + pidx)
        where
          (idx, e) = maximumBy cmp . zip [1 ..] . drop pidx $ take (length xs - curr) xs
   in fst . foldl step (0, 0) $ reverse [0 .. 11]

main :: IO ()
main = do
  input <- fmap (fmap digitToInt) . lines <$> readFile "input.txt"
  print . sum $ fmax <$> input
  return ()
