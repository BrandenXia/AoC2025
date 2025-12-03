module Main where

import Data.Char (digitToInt)
import Data.Foldable (maximumBy)

fmax :: [Int] -> Int
fmax xs = e * 10 + maximum (drop idx xs)
  where
    cmp (i1, x1) (i2, x2) = compare x1 x2 <> compare i2 i1
    (idx, e) = maximumBy cmp . zip [1 ..] $ init xs

main :: IO ()
main = do
  input <- fmap (fmap digitToInt) . lines <$> readFile "input.txt"
  print . sum $ fmax <$> input
  return ()
