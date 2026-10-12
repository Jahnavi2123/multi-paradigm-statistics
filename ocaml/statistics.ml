
let data = [4; 2; 7; 4; 9; 2; 4; 6; 2; 8]

let calculate_mean numbers =
  match numbers with
  | [] -> invalid_arg "Cannot calculate mean of an empty list"
  | _ ->
      let total = List.fold_left (+) 0 numbers in
      float_of_int total /. float_of_int (List.length numbers)

let calculate_median numbers =
  match numbers with
  | [] -> invalid_arg "Cannot calculate median of an empty list"
  | _ ->
      let sorted = List.sort compare numbers in
      let n = List.length sorted in
      if n mod 2 = 1 then
        float_of_int (List.nth sorted (n / 2))
      else
        let left = List.nth sorted (n / 2 - 1) in
        let right = List.nth sorted (n / 2) in
        (float_of_int left +. float_of_int right) /. 2.0

let calculate_mode numbers =
  let sorted = List.sort compare numbers in
  let frequencies =
    List.fold_left
      (fun counts value ->
        match counts with
        | (number, count) :: rest when number = value ->
            (number, count + 1) :: rest
        | _ -> (value, 1) :: counts)
      [] sorted
  in
  let max_count =
    List.fold_left
      (fun current (_, count) -> max current count)
      0 frequencies
  in
  if max_count <= 1 then []
  else
    frequencies
    |> List.filter (fun (_, count) -> count = max_count)
    |> List.map fst
    |> List.sort compare

let () =
  Printf.printf "OCaml - Functional Statistics\n";
  Printf.printf "Dataset: %s\n"
    (String.concat ", " (List.map string_of_int data));
  Printf.printf "Mean: %.2f\n" (calculate_mean data);
  Printf.printf "Median: %.2f\n" (calculate_median data);

  let modes = calculate_mode data in
  if modes = [] then
    Printf.printf "Mode: No mode (all values occur once)\n"
  else
    Printf.printf "Mode: %s\n"
      (String.concat ", " (List.map string_of_int modes))
