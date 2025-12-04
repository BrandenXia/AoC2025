use std::fs;

#[derive(Debug, PartialEq)]
enum Tile { Blank, Paper }
type MapData = Vec<Vec<Tile>>;
struct Map { d: Vec<Vec<Tile>>, h: usize, w: usize }

const SURROUNDING: [(isize, isize); 8] = [(1, 0), (-1, 0), (0, 1), (0, -1), (-1, -1), (-1, 1), (1, -1), (1, 1)];

fn check(map: &Map, i: usize, j: usize) -> usize {
    SURROUNDING.iter()
        .map(|(di, dj)| (di + i as isize, dj + j as isize) )
        .filter(|(ni, nj)| *ni >= 0 && *ni < map.h as isize && *nj >= 0 && *nj < map.w as isize
            && map.d[*ni as usize][*nj as usize] == Tile::Paper )
        .count()
}

fn main() {
    let input = fs::read_to_string("input.txt").unwrap();
    let mapd = input
        .lines()
        .map(|line| {
            line.chars()
                .map(|c| if c == '@' { Tile::Paper } else { Tile::Blank } )
                .collect()
        })
        .collect::<MapData>();
    let (h, w) = (mapd.len(), mapd[0].len());
    let map = Map { d: mapd, h, w };
    let res = map.d.iter()
        .enumerate()
        .map(|(i, row)|
            row.iter()
                .enumerate()
                .filter(|(j, _)| map.d[i][*j] == Tile::Paper && check(&map, i, *j) < 4 ).count()
        )
        .sum::<usize>();
    println!("{}", res);
}
