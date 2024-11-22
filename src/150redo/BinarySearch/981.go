type Entry struct {
  Value string
  Timestamp int
}

type TimeMap struct {
  Mp map[string][]Entry
}

func Constructor() TimeMap {
	return TimeMap{
		Mp: make(map[string][]Entry),
	}
}

func (this *TimeMap) Set(key string, value string, timestamp int) {
  if _, ok := this.Mp[key]; !ok {
    this.Mp[key] = []Entry{}
  }

  this.Mp[key] = append(this.Mp[key], Entry{Value: value, Timestamp: timestamp})
}

func (this *TimeMap) Get(key string, timestamp int) string {
  values, ok := this.Mp[key]
  if !ok {
    return ""
  }

  result := ""
  l, r := 0, len(values) - 1

  for l <= r {
    m := l + (r - l) / 2
    if values[m].Timestamp <= timestamp {
      result = values[m].Value
      l = m + 1
    } else {
      r = m - 1
    }
  }
  return result
}
